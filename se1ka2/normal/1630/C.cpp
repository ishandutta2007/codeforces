#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

template <typename T>
struct SegmentTree
{
    using F = function<T(T, T)>;
    
    const F f;
    const T e;
    
    int n;
    vector<T> seg;
    
    SegmentTree(int nn, const F f, const T e) : f(f), e(e){
        n = 1;
        while(n <= nn) n <<= 1;
        seg.assign(n * 2, e);
    }
    
    void set(int i, T x){
        seg[i + n] = x;
    }
    
    void build(){
        for(int k = n - 1; k > 0; k--){
            seg[k] = f(seg[k * 2], seg[k * 2 + 1]);
        }
    }
    
    void update(int i, T x){
        int k = i + n;
        seg[k] = x;
        while(k >>= 1){
            seg[k] = f(seg[k * 2], seg[k * 2 + 1]);
        }
    }
    
    T query(int l, int r){
        l += n, r += n;
        T L = e, R = e;
        for(; l != r; l >>= 1, r >>= 1){
            if(l % 2) L = f(L, seg[l++]);
            if(r % 2) R = f(seg[--r], R);
        }
        return f(L, R);
    }
    
    T operator[](const int i)const {
        return seg[i + n];
    }
    
    template<typename C>
    int right_bound_sub(int k, const C &check, T x){
        while(k < n){
            if(check(f(x, seg[k * 2]))){
                k = k * 2;
            }
            else{
                x = f(x, seg[k * 2]);
                k = k * 2 + 1;
            }
        }
        return k - n;
    }
    
    template <typename C>
    int right_bound(int i, const C &check){
        T x = e;
        for(int l = i + n, r = n * 2; l != r; l >>= 1, r >>= 1){
            if(l % 2){
                if(check(f(x, seg[l]))){
                    return right_bound_sub(l, check, x);
                }
                x = f(x, seg[l]);
                l++;
            }
        }
        return -1;
    }
    
    template <typename C>
    int left_bound_sub(int k, const C &check, T x){
        while(k < n){
            if(check(f(seg[k * 2 + 1], x))){
                k = k * 2 + 1;
            }
            else{
                x = f(seg[k * 2 + 1], x);
                k = k * 2;
            }
        }
        return k - n;
    }
    
    template <typename C>
    int left_bound(int i, const C &check){
        T x = e;
        for(int l = n, r = i + n; l != r; l >>= 1, r >>= 1){
            if(r % 2){
                if(check(f(seg[--r], x))){
                    return left_bound_sub(r, check, x);
                }
                x = f(x, seg[r]);
            }
        }
        return -1;
    }
};

int main()
{
	int n;
	cin >> n;
	int l[200005], r[200005];
	for(int i = 0; i < n; i++) l[i] = n, r[i] = -1;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		a--;
		l[a] = min(l[a], i);
		r[a] = max(r[a], i);
	}
	vector<P> v;
	int b[200005]{0};
	for(int i = 0; i < n; i++){
		if(l[i] < r[i]){
			b[l[i]]++;
			b[r[i] + 1]--;
			v.push_back(P(l[i], r[i]));
		}
	}
	for(int i = 1; i <= n; i++) b[i] += b[i - 1];
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(l[i] == r[i] && b[l[i]] == 0) ans++;
	}
	sort(v.begin(), v.end());
	SegmentTree<int> seg(n + 1, [](int a, int b){return max(a, b);}, 0);
	for(P p : v)seg.update(p.first, p.second);
	int k = v.size();
	if(k == 0){
		cout << n - ans << endl;
		return 0;
	}
	int ra = v[0].second;
	ans += 2;
	int i = 0;
	while(true){
		int rr = seg.query(0, ra);
		if(rr == ra){
			while(i < k && v[i].first < ra) i++;
			if(i == k) break;
			ans += 2;
			ra = v[i].second;
		}
		else{
			ans++;
			ra = rr;
		}
	}
	cout << n - ans << endl;
}