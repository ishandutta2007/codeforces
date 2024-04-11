#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e6 + 10;

set<pii> st;
set<int> ids;
int money[maxn];

int del(int id){
    ids.erase(id);
    st.erase({money[id], -id});
    return id;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    int ID = 1;
    while(q--){
	int task;
	cin >> task;
	if(task == 1){
	    cin >> money[ID];
	    st.insert({money[ID], -ID});
	    ids.insert(ID);
	    ID++;
	}
	if(task == 2){
	    cout << del(*ids.begin()) << " ";
	}
	if(task == 3){
	    cout << del(-st.rbegin()->S) << " ";
	}
    }
    return cout << endl, 0;
}