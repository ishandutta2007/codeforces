#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<char> v;
vector< pair<ll , ll> > a , b , c;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL);
    
	string s;
	cin>>s;
	ll n = s.size() , l = 0 , r , ans = -1;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '(' || s[i] == '['){
			v.push_back(s[i]);
		} else if(s[i] == ')'){
			if(v.empty()){
				r = i - 1;
				if(r > l){
					a.push_back( make_pair(l , r) );
				}
				l = i + 1;
			} else {
				char h = v[v.size() - 1];
				if(h != '('){
				    r = i - 1;
					if(r > l){
						a.push_back( make_pair(l , r) );
					}
					l = i + 1;
					v.clear();
				} else {
				v.pop_back();
				}
			}
		} else if(s[i] == ']'){
			if(v.empty()){
				r = i - 1;
				if(r > l){
					a.push_back( make_pair(l , r) );
				}
				l = i + 1;
			} else {
				char h = v[v.size() - 1];
				if(h != '['){
				    r = i - 1;
					if(r > l){
						a.push_back( make_pair(l , r) );
					}
					l = i + 1;
					v.clear();
				} else {
				v.pop_back();
				}
			}
		}
	}
	r = n - 1;
	if(r > l){
		a.push_back( make_pair(l , r) );
	}
	l = r + 1;
	v.clear();
	r = n - 1;
	for(int i = n - 1 ; i >= 0 ; i--){
		if(s[i] == ')' || s[i] == ']'){
			v.push_back(s[i]);
		} else if(s[i] == '('){
			if(v.empty()){
				l = i + 1;
				if(r > l){
					b.push_back( make_pair(l , r) );
				}
				r = i - 1;
			} else {
				char h = v[v.size() - 1];
				if(h != ')'){
				    l = i + 1;
					if(r > l){
						b.push_back( make_pair(l , r) );
					}
					r = i - 1;
					v.clear();
				} else {
					v.pop_back();
				}
			}
		} else if(s[i] == '['){
			if(v.empty()){
				l = i + 1;
				if(r > l){
					b.push_back( make_pair(l , r) );
				}
				r = i - 1;
			} else {
				char h = v[v.size() - 1];
				if(h != ']'){
				    l = i + 1;
					if(r > l){
						b.push_back( make_pair(l , r) );
					}
					r = i - 1;
					v.clear();
				} else {
					v.pop_back();
				}
			}
		}
	}
	l = 0;
	if(r > l){
		b.push_back( make_pair(l , r) );
	}
	v.clear();
	ll as = a.size() , bs = b.size();
	sort(b.begin() , b.end());
	ll x = 0 , y = 0;
	while(x < as && y < bs){
	    if(!(a[x].second < b[y].first || a[x].first > b[y].second)){
//            cout<<a[x].first<<" "<<a[x].second<<"  "<<b[y].first<<" "<<b[y].second<<"\n";
	        c.push_back( make_pair(max(a[x].first , b[y].first) , min(a[x].second , b[y].second)) );
	    }
	    if(a[x].second < b[y].second){
	        x++;
	    } else {
	        y++;
	    }
	}
	ll cs = c.size() , u = 0;
	if(cs == 0){
	    cout<<0<<"\n\n";
	    return 0;
	}
	for(int i = 0 ; i < cs ; i++){
	    ll o = c[i].first , p = c[i].second , counter = 0;
	    for(int j = o ; j <= p ; j++){
	        if(s[j] == '['){
	            counter++;
	        }
	    }
	    if(counter > ans){
	        ans = counter;
	        u = i;
	    }
	}
	cout<<ans<<"\n";
	for(int i = c[u].first ; i <= c[u].second ; i++){
	    cout<<s[i];
	}
	cout<<"\n";
	return 0;
}