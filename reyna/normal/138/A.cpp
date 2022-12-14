//In the name of God
#include <bits/stdc++.h>
using namespace std;
int n,k;
bool vowel(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
	return 0;
}
bool match(string S,string P){
	int cnt = 0;
	int p1 = -1;
	for(int i = S.size()-1; i + 1;i--){
		if(vowel(S[i])) cnt++;
		if(cnt == k){
			p1 = i;
			break;
		}
	}
	int p2 = -1;
	cnt = 0;
	for(int i = P.size()-1; i +1;i--){
		if(vowel(P[i])) cnt++;
		if(cnt == k){
			p2 = i;
			break;
		}
	}
	if(p1 == -1 || p2 == -1) return 0;
	if(S.size() - p1 != P.size() - p2) return 0;
	for(int i = 0; i < S.size() - p1 + 1;i++){
		if(S[p1+i] != P[p2+i]) return 0;
	}
	return 1;
}
int main(){
	cin >> n >> k;
	int a = 0,b = 0,c = 0,d = 0;
	for(int i = 0; i < n;i++){
		string s1,s2,s3,s4;
		cin >> s1 >> s2 >> s3 >> s4;
		if(match(s1,s2) && match(s2,s3) && match(s3,s4)){
			a++;
			continue;
		}
		if(match(s1,s4) && match(s2,s3)){
			b++;
			continue;
		}
		if(match(s1,s2) && match(s3,s4)){
			c++;
			continue;
		}
		if(match(s1,s3) && match(s2,s4)){
			d++;
			continue;
		}
	}
	if(a + b + c + d != n){
		cout << "NO\n";
		return 0;
	}
	if(a == n){
		cout << "aaaa\n";
		return 0;
	}
	if((b && c) || (c && d) || (b && d)){
		cout << "NO\n";
		return 0;
	}
	if(b){
		cout << "abba\n";
		return 0;
	}
	if(c){
		cout << "aabb\n";
		return 0;
	}
	if(d){
		cout << "abab\n";
		return 0;
	}
	return 0;
}