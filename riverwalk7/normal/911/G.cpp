#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    int lazy[100];
    int ss, ee, fan;
    int l, r;
    node(){}
    node(int ss, int ee, int fan){
        this->val = 0;
        this->ss = ss;
        this->ee = ee;
        this->fan = fan;
        this->l = this->r = -1;
        for(int i=0;i<100;i++) this->lazy[i] = i;
    }
};

int n;
int cnt = 0;
struct node stree[400005];
int su[200005];

int create_node(int ss, int ee, int fan){
    stree[cnt] = node(ss, ee, fan);
    cnt++;
    return cnt-1;
}

void upd(int idx, int ll, int rr, int from, int to){
    struct node *me = &stree[idx];
    if(ll == me->ss && me->ee == rr){
        me->val = 1;
        for(int i=0;i<100;i++){
            if(me->lazy[i] == from){
                me->lazy[i] = to;
            }
        }
        return;
    }
    int mid = ((me->ss + me->ee) >> 1);
    if(me->l == -1){
        me->l = create_node(me->ss, mid, idx);
    }
    if(me->r == -1){
        me->r = create_node(mid+1, me->ee, idx);
    }
    if(me->val){
        struct node *nl = &stree[me->l];
        struct node *nr = &stree[me->r];
        for(int i=0;i<100;i++){
            nl->lazy[i] = me->lazy[nl->lazy[i]];
            nr->lazy[i] = me->lazy[nr->lazy[i]];
        }
        for(int i=0;i<100;i++){
            me->lazy[i] = i;
        }
        nl->val = nr->val = 1;
        me->val = 0;
    }
    if(rr <= mid) upd(me->l, ll, rr, from, to);
    else if(ll > mid) upd(me->r, ll, rr, from, to);
    else{
        upd(me->l, ll, mid, from, to);
        upd(me->r, mid+1, rr, from, to);
    }
}

int getd(int idx, int x, int color){
    struct node *me = &stree[idx];
    int mid = ((me->ss + me->ee) >> 1);
    bool one = (x == me->ss && me->ee == x);
    bool two = (x <= mid && me->l == -1);
    bool three = (x > mid && me->r == -1);
    if(one || two || three){
        return me->lazy[color];
    }
    if(me->l == -1) me->l = create_node(me->ss, mid, idx);
    if(me->r == -1) me->r = create_node(mid+1, me->ee, idx);
    if(me->val){
        struct node *nl = &stree[me->l];
        struct node *nr = &stree[me->r];
        for(int i=0;i<100;i++){
            nl->lazy[i] = me->lazy[nl->lazy[i]];
            nr->lazy[i] = me->lazy[nr->lazy[i]];
        }
        for(int i=0;i<100;i++){
            me->lazy[i] = i;
        }
        nl->val = nr->val = 1;
        me->val = 0;
    }
    if(x <= mid) return getd(me->l, x, color);
    else return getd(me->r, x, color);
}

int main(){
    setbuf(stdout, NULL);
    scanf("%d",&n);
    create_node(0, n-1, -1);
    for(int i=0;i<n;i++){
        scanf("%d",&su[i]);
        su[i]--;
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int ll, rr, from, to;
        scanf("%d%d%d%d",&ll,&rr,&from,&to);
        ll--;rr--;from--;to--;
        upd(0, ll, rr, from, to);
    }
    for(int i=0;i<n;i++){
        printf("%d ", getd(0, i, su[i])+1);
    }
}