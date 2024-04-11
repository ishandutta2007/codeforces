#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



INT dp[(1<<18)+10][111], a[20], cnt[11];



int main() {

	INT n;

	int j,m, len=0;

	cin>>n>>m;

	INT tmp=n;

	

	while(tmp) a[len++]=tmp%10, tmp/=10, cnt[a[len-1]]++;

	sort(a, a+len);

	reverse(a, a+len);

	dp[0][0]=1;

	

	for(INT i=0; i<(1LL<<len)-1; i++){

		for(j=0; j<m; j++){

			for(int k=0; k<len; k++){

				if((i&(1LL<<k)))  continue;

				dp[i+(1LL<<k)][(j*10+a[k])%m]+=dp[i][j];

			}

		}

	}

	

	INT ans=dp[(1LL<<len)-1][0];

	

	if(a[len-1]==0){

		

		len--;

		tmp=dp[(1LL<<len)-1][0];

		

		ans-=tmp*cnt[0];

	}

	

	

	for(int i=0; i<10; i++){

		for(j=2; j<=cnt[i]; j++) ans/=j;

	}

	cout<<ans<<endl;



	return 0;

}