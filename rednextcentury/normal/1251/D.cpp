#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
long long s;
vector<pair<int,int> > v;
bool check(int mid) {
    int need = n/2+1;
    ll cur = s;
    for (auto p:v) {
        int l = p.first,r=p.second;
        if (r>=mid && need){
            need--;
            cur-=max(l,mid);
        } else {
            cur-=l;
        }
    }
    if (cur>=0 && need==0)return 1;
    return 0;
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        v.clear();
        scanf("%d%lld",&n,&s);
        for (int i=0;i<n;i++) {
            int l,r;
            scanf("%d%d",&l,&r);
            v.push_back({l,r});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int l=0,r=1e9;
        int ret=-1;
        while(l<=r) {
            int mid = (l+r)/2;
            if (check(mid))ret=mid,l=mid+1;
            else r=mid-1;
        }
        printf("%d\n",ret);
    }
}