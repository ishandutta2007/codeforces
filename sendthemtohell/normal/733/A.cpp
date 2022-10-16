#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int Is(char y){
	if(y == 'A' || y == 'E' || y == 'I' || y == 'O' || y == 'U' || y == 'Y')
		return 1;
	return 0;
}

int main(){
	string S;
	int n;
	//cin>>n;
	cin>>S;
	n=S.size();
	S.append("A",1);
	int ans=0,cu=0;
	for(int i=0;i<=n;i++){
		cu++;
	//	cout<<"cu="<<cu<<"    ";
		if(cu>ans){
			ans=cu;
		}
		if(Is(S[i])){
			cu=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}