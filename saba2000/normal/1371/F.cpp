#include<bits/stdc++.h>
#define mid ((l+r)/2)
using namespace std;
struct va{
    int pv, pl, sv, sl, l, p2, s2, m01, m10;
};
va emp = {0,0,0,0,0,0,0,0,0};
va comb(va A, va B){
    if(A.l == 0) return B;
    if(B.l == 0) return A;
    va C;
    C.l = A.l + B.l;
    C.pv = A.pv;
    C.sv = B.sv;
    if(A.pl == A.l){
        if(B.pv == A.pv)
            C.pl = A.l + B.pl,
            C.p2 = B.p2;
        else
            C.pl = A.pl,
            C.p2 = B.pl;
    }
    else {
        C.pl = A.pl;
        C.p2 = A.p2;
        if(A.pl + A.p2 == A.l && B.pv != A.pv)
            C.p2 += B.pl;
    }


    if(B.sl == B.l){
        if(A.sv == B.sv)
            C.sl = B.l + A.sl,
            C.s2 = A.s2;
        else
            C.sl = B.sl,
            C.s2 = A.sl;
    }
    else {
        C.sl = B.sl;
        C.s2 = B.s2;
        if(B.sl + B.s2 == B.l && A.sv != B.sv)
            C.s2 += A.sl;
    }
    C.m01 = max(A.m01, B.m01);
    C.m10 = max(A.m10, B.m10);
    if(A.sv == 0 && B.pv == 1)
        C.m01 = max(C.m01, A.sl + B.pl); else
    if(A.sv == 1 && B.pv == 0)
        C.m10 = max(C.m10, A.sl + B.pl); else
    if(A.sv == 0 && B.pv == 0){
        C.m01 = max(C.m01, A.sl + B.pl + B.p2);
        C.m10 = max(C.m10, A.sl + B.pl + A.s2);
    } else{
        C.m01 = max(C.m01, A.sl + B.pl + A.s2);
        C.m10 = max(C.m10, A.sl + B.pl + B.p2);
    }
    return C;
}

va flip(va &A){
    A.pv ^=1;
    A.sv ^=1;
    swap(A.m01, A.m10);
}
struct node{
    va val;
    int lz;
    node *L,  *R;
    void upd(){
        this->val = comb(this->L->val, this->R->val);
    }
    void lzu(){
        if(this->lz){
            flip(this->val);
            this->lz = 0;
            if(this->L)
                this->L->lz ^=1,
                this->R->lz ^=1;
        }
    }
};
int A[500009];
//int pv, pl, sv, sl, l, p2, s2, m01, m10;
void build(node *&x, int l, int r){
    x = new node();
    if(l == r){
        x->val = {A[l], 1, A[l], 1, 1, 0, 0, 1, 1};
        return;
    }
    build(x->L, l, mid);
    build(x->R, mid+1, r);
    x->upd();
}
void upd(node *&x, int l, int r, int a, int b){
    x->lzu();

    if(l >= a && r <= b){
        x->lz = 1;
        x->lzu();
        return;
    }
    if(l > b || r < a) return;
    upd(x->L, l, mid, a, b);
    upd(x->R, mid+1, r, a, b);
    x->upd();
}
va cnt(node *&x, int l, int r, int a, int b){
    x->lzu();
    if(l >= a && r <= b)
        return x->val;
    if(l > b || r < a) return emp;
    return comb(cnt(x->L, l, mid,a,b),
                cnt(x->R, mid+1,r,a,b));
}
main(){
    ios_base::sync_with_stdio(false);
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    for(int i = 1; i <= n; i++)
        if(s[i-1] == '>') A[i] = 1;
    node *rt;
    build(rt, 1, n);
    while(q--){
        int l, r;
        cin>>l>>r;
        upd(rt, 1, n, l, r);
        va ans = cnt(rt, 1, n, l, r);
        cout <<ans.m10<<endl;
    }




}