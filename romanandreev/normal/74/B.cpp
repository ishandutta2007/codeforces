#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
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
int n,m,k,v;
char s[1000];
int gd[1000];
void hodk(){
	m+=v;
	if (m==n){
		m=n-2;
		v=-v;
	} else
	if (m==-1){
		m=1;
		v=-v;
	}
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%d%d\n",&n,&k,&m);
    m--;
    k--;
    for (int i=0;i<n;i++){
    	gd[i]=0;
    }
    gd[k]=1;
    gets(s);
    if (s[3]=='h') v=-1; else v=1;
    gets(s);
    for (int j=0;s[j];j++){
    	if (s[j]=='1'){
    		hodk();
    		for (int i=0;i<n;i++) gd[i]=1;
    		gd[m]=0;
    	} else {
    		for (int i=0;i<n;i++) {
    			if (gd[i]==1 && i>0 && m!=i-1){
    				gd[i-1]=1;
    			}
    			if (gd[i]==1 && i<n-1 && m!=i+1){
    				gd[i+1]=1;
    			}
    		}
    		hodk();
    		gd[m]=0;
    		bool bol=true;
    		for (int i=0;i<n;i++) if (gd[i]==1)
    			bol=false;
    		if (bol){
    			cout<<"Controller "<<j+1<<endl;
    			return 0;
    		}
    	}
    }
    cout<<"Stowaway"<<endl;
    return 0;
}