#include<bits/stdc++.h>



using namespace std;



int k, i, d, ans[110], v, ok=1, ook=1, o;



int main(){

	

	scanf("%d", &k);

	for(i=0; i<k; i++){

		scanf("%d", &d);

		if(d==0||d==100) ans[o++]=d;

		if(d>0&&d<10&&ok) ans[o++]=d, ok=0;

		if(d>9&&d<100&&d%10==0&&ook) ans[o++]=d, ook=0;

		if(d>9&&d%10) v=d;

	}

	

	if(ok&&ook&&v) ans[o++]=v;



	printf("%d\n", o);

	for(i=0;i<o;i++) printf("%d ", ans[i]);

	return 0;

}