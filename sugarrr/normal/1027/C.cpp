#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=1000000000000;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}


//////////////////////////////////////

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        int a[n];rep(i,0,n-1)scanf("%d",&a[i]);
        sort(a,a+n);
        vector<int>v;
        int pos=0;
        bool flag4=false;int ans4=-1;
        while(pos<=n-1){
            int count=1;
            while(pos<=n-2&&a[pos]==a[pos+1]){
                count++;
                pos++;
            }
            if(count>=4){
                flag4=true;
                ans4=a[pos];
                break;
            }else if(count>=2){
                v.push_back(a[pos]);
            }
            pos++;
        }
        if(flag4==true){
            rep(i,1,4)printf("%d ",ans4);
            printf("\n");
        }else{
            int size=v.size();
            
            double minans=(double)v[1]/(double)v[0];
            int posans=0;
            rep(i,1,size-2){
                double kouhoans=(double)v[i+1]/(double)v[i];
                if(kouhoans<minans){
                    minans=kouhoans;
                    posans=i;
                }
            }
            printf("%d %d %d %d\n",v[posans],v[posans],v[posans+1],v[posans+1]);
        }
        
    }
    
    return 0;
}