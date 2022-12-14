#include<bits/stdc++.h>
using namespace std;
#define ll long long
int l[1000000];
int d[1000000];
int num[300];
vector<int> vec[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)cin>>l[i];
    for (int i=1;i<=n;i++)cin>>d[i], vec[l[i]].push_back(d[i]) , num[d[i]]++;
    ll sum=0;
    int tot = n;
    ll ret=1e12;
    for (int i=1e5;i>=1;i--){
        for (auto x:vec[i])num[x]--;
        if (vec[i].size()==0)continue;
        tot -= vec[i].size();
        int mx = vec[i].size()-1;
        int rem = tot - mx;
        ll cost=sum;
        for (int j=1;j<=200;j++){
            if (rem<=0)break;
            if (num[j]>=rem){
                cost+=j*rem;
                rem=0;
            } else {
                cost+=j*num[j];
                rem-=num[j];
            }
        }
        ret=min(ret,cost);
        for (auto x:vec[i])sum+=x;
    }
    cout<<ret<<endl;
}