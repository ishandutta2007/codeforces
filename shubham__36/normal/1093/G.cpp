#include <bits/stdc++.h>
// #include <set>
// #include <list>
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <map>
// #include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef unordered_map<int,int> m32;
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
ll MOD = 998244353;
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// string s,p;
// ll t,n,m,ans,a,b1,c,c1;
// vv64 g;
// v32 vis;
// bool b;












void construct_segment_tree(vector<int>& segtree, 
                            vector<int>& a, int n) 
{ 
    // assign values to leaves of the segment tree 
    // cout << segtree.size() << " " << a.size() << " " << n << ln;
    for (int i = 0; i < n; i++) 
        segtree[n + i] = a[i]; 
  
    /* assign values to internal nodes 
    to compute maximum in a given range */
    for (int i = n - 1; i >= 1; i--) 
        segtree[i] = max(segtree[2 * i], 
                         segtree[2 * i + 1]); 
} 
  
void update(vector<int>& segtree, int pos, int value, 
            int n) 
{ 
    // change the index to leaf node first 
    pos += n; 
  
    // update the value at the leaf node 
    // at the exact index 
    segtree[pos] = value; 
  
    while (pos > 1) { 
  
        // move up one level at a time in the tree 
        pos >>= 1; 
  
        // update the values in the nodes in 
        // the next higher level 
        segtree[pos] = max(segtree[2 * pos], 
                           segtree[2 * pos + 1]); 
    } 
} 
  
int range_query(vector<int>& segtree, int left, int
                                                    right, 
                int n) 
{ 
    /* Basically the left and right indices will move 
        towards right and left respectively and with 
        every each next higher level and compute the  
        maximum at each height. */
    // change the index to leaf node first 
    left += n; 
    right += n; 
  
    // initialize maximum to a very low value 
    int ma = INT_MIN; 
  
    while (left < right) { 
  
        // if left index in odd 
        if (left & 1) { 
            ma = max(ma, segtree[left]); 
  
            // make left index even 
            left++; 
        } 
  
        // if right index in odd 
        if (right & 1) { 
  
            // make right index even 
            right--; 
  
            ma = max(ma, segtree[right]); 
        } 
  
        // move to the next higher level 
        left /= 2; 
        right /= 2; 
    } 
    return ma; 
} 











int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,temp;
    cin >> n >> k;
    vv32 val(k,std::vector<int>(n));
    vv32 a(2*((int)1<<k),std::vector<int>(n,0));
	forn(i,n){
		forn(j,k){
			cin >> val[j][i];
		}
		forn(z,(1<<k)){
			forn(j,k){
				if((1<<j)&z) a[z][i]-=val[j][i];
				else a[z][i]+=val[j][i];
			}
		}
	}
	forn(i,n){
		forn(z,(1<<k)){
			forn(j,k){
				a[z+(1<<k)][i]=a[z][i];
				a[z+(1<<k)][i]*=(ll)-1;
			}
		}
	}
	vv32 st(2*((int)1<<k),std::vector<int>(2*n));
// 	forn(i,(int)st[0].size()) cout << st[0][i] << "a ";
// 	forn(i,(int)a[0].size()) cout << a[0][i] << "b ";
// 	cout << n << ln;
// 	construct_segment_tree(st[0], a[0], n);
	forn(i,2*((int)1<<k)) construct_segment_tree(st[i], a[i], n);
	ll q,t;
	cin >> q;
	forn(hgas,q){
		cin >> t;
		if(t==2){
			int j,k1;
			cin >> j >> k1;
			int ans=0;
			forn(i,((int)1<<k)){

				int vf = range_query(st[i], j-1, k1,n);
				// cout << st.size() << " " << i+(1<<k) << ln;
				int vc = range_query(st[i+(1<<k)], j-1, k1,n);
				// cout << "correct" << ln;
				ans = max(ans,vf+vc);
			}
			cout << ans << ln;
		}
		else{
			int in;
			v32 a1(((int)1<<k),0),val1(k);
			cin >> in;
			forn(i,k) cin >> val1[i];
			forn(z,((int)1<<k)){
				forn(j,k){
					if((1<<j)&z) a1[z]-=val1[j];
					else a1[z]+=val1[j];
				}
			}
			forn(z,((int)1<<k)){
				update(st[z], in-1, a1[z], n);
				update(st[z+(1<<k)], in-1, (ll)(-1)*a1[z], n);
			}
		}
	}
}