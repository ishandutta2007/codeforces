#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



char ham[111];

int cnt[200];

INT r;

int pb, ps, pc, nb, ns, nc;

int can(INT mid){

	INT b=max(0LL, mid*cnt['B']-nb);

	INT s=max(0LL, mid*cnt['S']-ns);

	INT c=max(0LL, mid*cnt['C']-nc);

	INT val=b*pb+s*ps+c*pc;

	

	if(val<=r) return 1;

	else return 0;

	

}



int main() {

	

	scanf("%s", ham);

	for(int i=0; i<strlen(ham); i++){

		cnt[ham[i]]++;

	}

	cin>>nb>>ns>>nc>>pb>>ps>>pc;

	

	cin>>r;

	

	INT st=0, ed=100000000000000LL;

	while(ed>st+1){

		INT mid=(st+ed)/2;

		if(can(mid)) st=mid;

		else ed=mid;

	}

	cout<<st<<endl;

	



	return 0;

}