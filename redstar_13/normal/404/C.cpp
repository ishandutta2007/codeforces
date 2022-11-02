#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



pii d[NN];

pii ans[NN];

int arr[NN];



int main() {

	int n,k,i,j;

	cin>>n>>k;

	

	for(i=1; i<=n; i++){

		scanf("%d", &d[i].first); d[i].second=i;

	}

	

	sort(d+1, d+n+1);

	

	if(d[1].first!=0 || d[2].first==0) return puts("-1"), 0;

	

	int len=1;

	int st=1, ed=1, step=0;

	arr[1]=d[1].second;

	

	for(i=2; i<=n; ){

		if(d[i].first!=len) return puts("-1"), 0;

		

		while(d[i].first==len){

			if(len==1 && step>=k) return puts("-1"), 0;

			if(len!=1 && step>=(INT)(ed-st+1)*(k-1)) return puts("-1"), 0;

			arr[i]=d[i].second;

			ans[i]=pii(arr[st+step%(ed-st+1)], d[i].second);

			step++;

			i++;

		}

		st=ed+1, ed=i-1;

		len++;

		step=0;

	}

	

	cout<<n-1<<endl;

	for(i=2; i<=n; i++) printf("%d %d\n", ans[i].first, ans[i].second);

	





	return 0;

}