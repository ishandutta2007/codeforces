// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 5e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

ll val1[maxn], val2[maxn], p[maxn];
int a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	cin >> a[i];
    }
    {
	stack<int> st;
	ll num = 0;
	for(int i = 0; i < n; i++){
	    while(sz(st) && a[st.top()] >= a[i])
		num-= p[st.top()], st.pop();
	    p[i] = 1ll * a[i] * (i- (st.empty() ? -1 : st.top()));
	    st.push(i);
	    num+= p[i];
	    val1[i] = num;
	}
    }
    {
	stack<int> st;
	ll num = 0;
	for(int i = n-1; i >= 0; i--){
	    while(sz(st) && a[st.top()] >= a[i])
		num-= p[st.top()], st.pop();
	    p[i] = 1ll * a[i] * ((st.empty() ? n : st.top()) - i);
	    st.push(i);
	    num+= p[i];
	    val2[i] = num;
	}
    }

    ll ans = -1;
    int pos = -1;
    for(int i = 0; i < n; i++){
	if(ans < val1[i] + val2[i] - a[i])
	    ans = val1[i] + val2[i] - a[i], pos = i;
    }
    for(int i = pos+1; i < n; i++){
	a[i] = min(a[i], a[i-1]);
    }
    for(int i = pos-1; i >= 0; i--){
	a[i] = min(a[i], a[i+1]);
    }
    for(int i = 0; i < n; i++){
	cout << a[i] << " ";
    }
    return cout << endl, 0;
}