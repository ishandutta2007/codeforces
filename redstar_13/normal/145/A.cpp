#include<bits/stdc++.h>



#define pb push_back

#define mod 1000000007

#define inf 1000000000

#define INF 1000000000000000000LL

#define MAX(a,b,c) max(a, max(b, c))

#define MIN(a, b, c) min(a, min(b, c))





using namespace std;

typedef long long INT;

typedef pair<int ,int > pii;



#define NN 111111

char a[NN], b[NN];



int main(){

	cin>>a>>b;

	

	int cnt=0, cnt1=0;

	for(int i=0; i<strlen(a); i++){

		if(a[i]=='4' && b[i]=='7') cnt++;

		if(a[i]=='7' && b[i]=='4') cnt1++;

	}

	

	cout<<max(cnt, cnt1)<<endl;

	

	return 0;

}