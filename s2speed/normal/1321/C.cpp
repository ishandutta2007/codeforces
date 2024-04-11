#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

string del(string s , ll q){
	string h;
	for(int i = 0 ; i < s.size() ; i++){
		if(i != q){
			h += s[i];
		}
	}
	return h;
}

int main(){
	ll n , counter = 0;
	string s;
	cin>>n>>s;
	for(int i = 122 ; i > 97 ; i--){
		for(int j = 0 ; j < s.size() ; j++){
			bool ch;
			if(s[j] == i){
				if(j == 0){
					ch = true;
				} else {
					ch = false;
				}
				if(ch == false){
					if(s[j - 1] == i - 1){
					counter++;
						s = del(s , j);
						j--;
						continue;
					}
				}
				for(int h = j + 1 ; h < s.size() ; h++){
					if(s[h] == i - 1){
						counter += h - j;
						for(int q = j ; q < h ; q++){
							s = del(s , j);
						}
						break;
					} else if(s[h] != i){
						j = h + 1;
						break;
					}
				}
			}
		}
	}
	cout<<counter<<endl;
	return 0;
}