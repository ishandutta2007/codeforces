#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debug puts("isok")
using namespace std;

int n,a[200005],now=0,res=0,h;
ll ans;

int main(){
    scanf("%d",&n);
    //ans=a[1];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!ans) ans=a[i]; else ans=min(ans,(ll)a[i]);
    }
    for(int i=1;i<=n;i++)
        if((ll)a[i]>ans) h=i; else break;
    for(int i=1;i<=n;i++){
        if((ll)a[i]>ans) now++; else now=0;
        res=max(res,now);
    }
    ans=ans*n+max(res,now+h);
    cout<<ans<<endl;
    return 0;
}