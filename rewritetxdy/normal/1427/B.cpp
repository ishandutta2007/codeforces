#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int t,n,k,a[200020],cnt;
char c[200010];

int main()
{
	scanf("%d",&t);
	while(t--){
		cnt = 0;
		scanf("%d%d",&n,&k);
		scanf("%s",c+1);
		if(n == 1){
			printf("%d\n",c[1] == 'W' || k);
			continue;
		}
		int sum = 0,las = 0,tot = 0;
		for(int i=1;i <= n && c[i] != 'W';i++) tot++;
		for(int i=n;i >= 1 && c[i] != 'W';i--) tot++;
		for(int i=1;i <= n;i++){
			if(c[i] == 'W'){
				sum += c[i-1] == 'W' ? 2 : 1;
				if(!las) las = i;
				else if(i-1 > las) a[++cnt] = i-las-1;
				las = i;
			}
		}
		if(!cnt){
			if(tot != 2*n) printf("%d\n",sum+min(k,tot)*2);
			else printf("%d\n",max(0,min(k,n)*2-1));
		}
		else{
			sort(a+1,a+1+cnt);
			for(int i=1;i <= cnt;i++){
				if(k < a[i]){
					sum += k*2;
					k = 0;
					break;
				}
				sum += a[i]*2+1 , k -= a[i];
			}
			sum += min(tot,k)*2;	
			printf("%d\n",sum);
		}
	}
}