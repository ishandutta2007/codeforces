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
char s[1000];
string a[1000];
int n,tk,ff;
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    gets(s);
    n=strlen(s);
    int tk=0;
    for (int i=0;i<n;i++){
    	if (s[i]==' ') {
/*    		ff=i;
    		while (s[ff]==' '){
    			ff++;
    		}
    		if (ff>i){
    			a[tk]=" ";
	    		tk++;
    			i=ff-1;
    			continue;
	    	}           */
	    	continue;
    	}
       	if (s[i]=='.'){
       		if (tk>0 && a[tk-1]!=" "){
       			a[tk++]=" ";
       		}
    		a[tk]="...";
    		tk++;
    		i+=2;
    		continue;
    	}
    	ff=i;
    	while (s[ff]>='0' && s[ff]<='9'){
    		ff++;
    	}
    	if (ff>i){
    		if (tk>0 && a[tk-1][0]>='0' && a[tk-1][0]<='9'){
       			a[tk++]=" ";
       		}
    		for (int j=i;j<ff;j++)
    			a[tk]+=s[j];
    		tk++;
    		i=ff-1;
    		continue;
    	}
    	a[tk++]=s[i];
    	a[tk++]=" ";
    }
    if (tk>0 && a[tk-1]==" ") tk--;
    for (int i=0;i<tk;i++)
    	cout<<a[i];
    cout<<endl;
    return 0;
}