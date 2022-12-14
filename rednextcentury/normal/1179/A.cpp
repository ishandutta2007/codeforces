#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<int,int> ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    deque<int> q;
    for (int i=1;i<=n;i++) {
        int x;
        cin>>x;
        q.push_back(x);
    }
    for (int i=1;i<=n;i++) {
        int A = q.front(); q.pop_front();
        int B = q.front(); q.pop_front();
        ret[i] = {A,B};
        if (A<B)swap(A,B);
        q.push_back(B);
        q.push_front(A);
    }
    int A = q.front();
    q.pop_front();
    while(m--){
        ll x;
        cin>>x;
        if (x<=n){
            cout<<ret[x].first<<' '<<ret[x].second<<endl;
        } else {
            x-=n+1;
            x%=(n-1);
            cout<<A<<' '<<q[x]<<endl;
        }
    }
}