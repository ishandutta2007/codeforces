#include<bits/stdc++.h>
using namespace std;
#define ll long long
string L,R;
int T;
ll dp[101][2][2][2][2];
int vis[101][2][2][2][2];
bool Can(int x,int pos,bool l,bool r)
{
    if (r && (R[pos]=='0' && x==1))return 0;
    if (l && (L[pos]=='1' && x==0))return 0;
    return 1;
}
ll sol(int pos,bool l1,bool r1,bool l2,bool r2) {
    if (pos==30)return 1;
    if (vis[pos][l1][r1][l2][r2]==T)return dp[pos][l1][r1][l2][r2];
    vis[pos][l1][r1][l2][r2]=T;
    ll &ret = dp[pos][l1][r1][l2][r2];
    ret=0;
    if (Can(0,pos,l1,r1) && Can(0,pos,l2,r2)) {
        bool newL1 = (l1 && (L[pos]=='0'));
        bool newR1 = (r1 && (R[pos]=='0'));
        bool newL2 = (l2 && (L[pos]=='0'));
        bool newR2 = (r2 && (R[pos]=='0'));
        ret+=sol(pos+1,newL1,newR1,newL2,newR2);
    }
    if (Can(0,pos,l1,r1) && Can(1,pos,l2,r2)) {
        bool newL1 = (l1 && (L[pos]=='0'));
        bool newR1 = (r1 && (R[pos]=='0'));
        bool newL2 = (l2 && (L[pos]=='1'));
        bool newR2 = (r2 && (R[pos]=='1'));
        ret+=sol(pos+1,newL1,newR1,newL2,newR2);
    }
    if (Can(1,pos,l1,r1) && Can(0,pos,l2,r2)) {
        bool newL1 = (l1 && (L[pos]=='1'));
        bool newR1 = (r1 && (R[pos]=='1'));
        bool newL2 = (l2 && (L[pos]=='0'));
        bool newR2 = (r2 && (R[pos]=='0'));
        ret+=sol(pos+1,newL1,newR1,newL2,newR2);
    }
    return ret;
}
string toBin(int x){
    string ret = "";
    for (int i=0;i<30;i++) {
        ret+=char(x%2+'0');
        x/=2;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        T++;
        int l,r;
        cin>>l>>r;
        L=toBin(l);
        R=toBin(r);
        ll ret = sol(0,1,1,1,1);
        cout<<ret<<endl;
    }
}