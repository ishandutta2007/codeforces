#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

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

int lf(int i, int *l){
	if(i == -1 || l[i] == i) return i;
	return l[i] = lf(l[i], l);
}

int rh(int i, int *r){
	if(r[i] == i) return i;
	return r[i] = rh(r[i], r);
}

int main()
{
	int n, q;
	cin >> n >> q;
	int a[200005], b[200005];
	for(int i = 0; i <= n; i++) a[i] = b[i] = i;
	SegmentTree<int> seg(n, [](int a, int b){return min(a, b);}, n + 3);
	while(q--){
		int t;
		cin >> t;
		if(t == 0){
			int l, r, x;
			cin >> l >> r >> x;
			l--;
			if(x == 0){
				vector<int> v;
				int i = l;
				while(i < r){
					v.push_back(i);
					i = max(i + 1, b[i]);
				}
				for(int i : v) a[i] = lf(min(a[i], i - 1), a);
				reverse(v.begin(), v.end());
				for(int i : v) b[i] = rh(max(b[i], i + 1), b);
			}
			else{
				seg.update(l, min(seg[l], r));
			}
		}
		else{
			int j;
			cin >> j;
			j--;
			if(a[j] != j) cout << "NO" << endl;
			else{
				int l = lf(j - 1, a) + 1, r = rh(j + 1, b);
				if(seg.query(l, j + 1) <= r) cout << "YES" << endl;
				else cout << "N/A" << endl;
			}
		}
	}
}