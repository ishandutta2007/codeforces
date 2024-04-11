#include<bits/stdc++.h>



using namespace std;



int n, k, i, ans=-1000000000, f, t;



int main(){

	

//	freopen("in.txt", "r", stdin);

	

	scanf("%d%d", &n, &k);

	while(n--){

		scanf("%d%d", &f, &t);

		if(t>k) ans=max(ans, f-t+k);

		else ans=max(ans, f);

	}

	printf("%d\n",ans);

	return 0;

}