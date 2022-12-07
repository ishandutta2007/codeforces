#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<memory.h>

using namespace std;

int n,h,xx,v,x,d,k;
long double ans;
char c,t[111];
map<int,int>m,w;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d%d\n",&h,&n);
	cout.precision(5);
	for (int i=0;i<n;i++){
		scanf("%c",&c);
		if (c=='a'){
			scanf("%c%c%d%d\n",&c,&c,&xx,&v);
			x=xx;
			w[x]+=v;
        		while (x){
        			m[x]+=v;
        			x/=2;
        		}
		}else{
			gets(t);
			x=1;
			ans=0;
			d=0;
			k=0;
			for(;;){
				int ww=w[x],l=m[x+x],r=m[x+x+1];
				if (d==h){
					ans+=max(k,ww)/(double)(1<<h);
					break;
				}
				if (l>r){
					ans+=max(k,ww+l)/(double)(1<<h)*(1<<(h-d-1));
					k=max(k,ww+r);
					x=x+x;
				}else{
					ans+=max(k,ww+r)/(double)(1<<h)*(1<<(h-d-1));
					k=max(k,ww+l);
					x=x+x+1;
				}
				d++;
			}
			cout << fixed << ans << endl;
		}
	}
	return 0;
}