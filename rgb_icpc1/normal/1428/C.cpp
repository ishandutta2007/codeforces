#include<bits/stdc++.h>

using namespace std;

#define M 200005

char s[M], str[M];

int main(){
	
//	freopen("in.txt", "r", stdin);

	int t, i;
	
	cin >> t;
	
	while(t --){
		cin >> s;
		
		int len = strlen(s), pre = -1;
		
		for(i = 0; i < len; i ++){
			if(pre == -1){
				pre = 0;
				str[pre] = s[i];
				continue;
			}
			if(str[pre] == 'A' && s[i] == 'B'){
				pre --;
				continue;
			}
			if(str[pre] == 'B' && s[i] == 'B'){
				pre --;
				continue;
			}
			str[++ pre] = s[i];
		}
		
		cout << pre + 1 << endl;
	}
	
	return 0;
}