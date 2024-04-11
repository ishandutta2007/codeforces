// b o t //
// l b m b h //
// b b b //
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long a[3],b[3];
	vector <pair <long long ,long long > > se;
	for (int i=0; i<3; i++){
		cin >> a[i] >> b[i];
		se.push_back({a[i],b[i]});
	}
	sort(se.begin(),se.end());
	long long maxx=abs(se[0].first-se[2].first)+abs(se[0].second-se[2].second);
	if (se[1].second>=se[0].second && se[1].second <=se[2].second){
		cout << 4 <<"\n";
		cout << se[0].first <<" "<< se[0].second <<" "<< se[1].first <<" "<< se[0].second <<"\n";
		cout << se[1].first <<" "<< se[0].second <<" "<< se[1].first <<" "<< se[1].second<<"\n";
		cout << se[1].first <<" "<< se[1].second <<" "<< se[2].first <<" "<<se[1].second <<"\n"; 
		cout << se[2].first <<" "<< se[1].second <<" "<< se[2].first <<" "<< se[2].second <<"\n";
	}else if (se[1].second<=se[0].second && se[1].second >=se[2].second){
		cout << 4 <<"\n";
		cout << se[0].first <<" "<< se[0].second <<" "<< se[1].first <<" "<< se[0].second <<"\n";
		cout << se[1].first <<" "<< se[0].second <<" "<< se[1].first <<" "<< se[1].second<<"\n";
		cout << se[1].first <<" "<< se[1].second <<" "<< se[2].first <<" "<<se[1].second <<"\n"; 
		cout << se[2].first <<" "<< se[1].second <<" "<< se[2].first <<" "<< se[2].second <<"\n";
	}else if (se[1].second>se[0].second && se[1].second>se[2].second){
			if (abs(se[1].second -se[2].second) <=abs(se[1].second-se[0].second)){
				cout <<3 <<"\n";
				cout << se[2].first <<" "<< se[2].second <<" "<<  se[0].first <<" "<<se[2].second <<"\n";
				cout << se[0].first << " "<< se[2].second <<" "<< se[0].first <<" "<< se[0].second <<"\n";
				cout << se[1].first <<" "<< se[1].second <<" "<< se[1].first <<" "<< se[2].second; 
			}else{
				cout <<3 <<"\n";
				cout << se[0].first <<" "<< se[0].second <<" "<<  se[2].first <<" "<<se[0].second <<"\n";
				cout << se[2].first << " "<< se[0].second <<" "<< se[2].first <<" "<< se[2].second <<"\n";
				cout << se[1].first <<" "<< se[1].second <<" "<< se[1].first <<" "<< se[0].second;
			}
		}else if (se[1].second<se[0].second && se[1].second <se[2].second){
			if (abs(se[1].second -se[2].second) <=abs(se[1].second-se[0].second)){
				cout <<3 <<"\n";
				cout << se[2].first <<" "<< se[2].second <<" "<<  se[0].first <<" "<<se[2].second <<"\n";
				cout << se[0].first << " "<< se[2].second <<" "<< se[0].first <<" "<< se[0].second <<"\n";
				cout << se[1].first <<" "<< se[1].second <<" "<< se[1].first <<" "<< se[2].second; 
			}else{
				cout <<3 <<"\n";
				cout << se[0].first <<" "<< se[0].second <<" "<<  se[2].first <<" "<<se[0].second <<"\n";
				cout << se[2].first << " "<< se[0].second <<" "<< se[2].first <<" "<< se[2].second <<"\n";
				cout << se[1].first <<" "<< se[1].second <<" "<< se[1].first <<" "<< se[0].second;
			}
		} 
}