#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> canMove;
bool can[1000000];
vector<vector<int> > ret;
int n,k;
string s;
void go(int i){
    swap(s[i],s[i-1]);
    can[i]=0;
}
void upd(int i){
    if (i<=0 || i>=n || can[i])return;
    if (s[i]=='L' && s[i-1]=='R'){
        can[i]=1;
        canMove.push_back(i);
    }
}
char inp[1000000];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%d%d",&n,&k);
    scanf("%s",inp);
    s=inp;
    ll mx = 0;
    int R=0;
    for (int i=0;i<n;i++){
        if (s[i]=='L')mx+=R;
        else R++;
        if (i && s[i]=='L' && s[i-1]=='R')canMove.push_back(i),can[i]=1;
    }
    for (int i=0;i<k;i++){
        int pos = canMove.size();
        ll need=0;
        if (mx - pos >= k-i-1) need = pos;
        else need = mx - (k-i-1);
        mx-=need;
        if (need<=0){
            cout<<-1<<endl;
            return 0;
        }
        vector<int> take;
        vector<int> ids;
        while(need--)take.push_back(canMove.back()), ids.push_back(canMove.back()), canMove.pop_back();
        ret.push_back(ids);
        for (auto x:take)go(x);
        for (auto x:take)upd(x-1),upd(x+1);
    }
    if (canMove.size()>0 || mx>0){
        cout<<-1<<endl;
        return 0;
    }
    for (const auto& x:ret){
        printf("%d",(int)x.size());
        for (auto y:x)printf(" %d",y);
        printf("\n");
    }
}