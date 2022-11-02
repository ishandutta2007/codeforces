#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int flag[NN], pre[NN], vst[NN], ans[NN], tmp[NN], cnt[NN];



int main() {

	int n,i,j;

	cin>>n;

	for(i=1; i<=n; i++) scanf("%d", flag+i);

	for(i=1; i<=n; i++) scanf("%d", pre+i), cnt[pre[i]]++;

	

	int dst=0;

	for(int p=1; p<=n; p++) {

		if(!flag[p]) continue;

		int k=0;

		i=p;

		tmp[k++]=i; 

		while(pre[i] && cnt[pre[i]]==1 && !flag[pre[i]]){

			i=pre[i];

			tmp[k++]=i;

		}

		if(k>=dst){

			dst=k;

			for(j=0; j<k; j++) ans[j]=tmp[k-j-1];

		}

		

	}



	cout<<dst<<endl;

	for(i=0; i<dst; i++) printf("%d ", ans[i]);



	return 0;

}