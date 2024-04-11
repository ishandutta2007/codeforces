#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
int tk[3];
int x[3];
int k;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>x[0]>>x[1]>>x[2]>>k;
    k=min(k,x[0]-1+x[1]-1+x[2]-1);
    tk[0]=1;
    tk[1]=1;
    tk[2]=1;
    for (int i=0;i<k;i++){
    	int mn=-1;
    	for (int j=0;j<3;j++) if (tk[j]<x[j] && (mn==-1 || tk[j]<tk[mn])){
    		mn=j;
    	}
    	tk[mn]++;
    }
    cout<<((ll)tk[0])*((ll)tk[1])*tk[2]<<endl;
    return 0;
}