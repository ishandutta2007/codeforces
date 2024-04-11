// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

// Set Power Series Library from dario2994's submission of arc105-F

// The class SubsetFunction<T> represents a function on the subsets of
// {0, 1, ..., N-1} with values in T. A subset is represented by its bitmask.
// The following operations are supported:
//  xor_convolution
//  and_convolution
//  or_convolution
//  subset_convolution
//  complement
//  exp
//  log
//
// Only the high-level API (that is SubsetFunction) shall be used.
// With respect to copy and assignment, the class SubsetFunction behaves like
// a vector.
// 
// Internally, all operations are implemented directly on arrays (and, whenever
// possible, in place). There are no memory leaks.
// Operating directly on arrays simplifies the implementation (since often one
// has to treat a subarray as an array and with vectors this is not possible).


// All functions in internal operate on pointers and are, therefore, a bit
// uncomfortable to use for the end-user.
// It is much better to use the fancier APIs offered by the class SubsetFunction.
namespace internal {

template<typename T>
void clear(int N, T* A) { fill(A, A+(1<<N), 0); }

// In place xor-transform. See xor_convolution to understand its importance.
// A'[x] = TODO.
// Complexity: O(N*2^N).
template<typename T>
void xor_transform(int N, T* A, bool inverse = false) {
    for (int len = 1; 2 * len <= (1<<N); len *= 2) {
        for (int x = 0; x < (1<<N); x += 2 * len) {
            for (int y = 0; y < len; y++) {
                T u = A[x + y];
                T v = A[x + y + len];
                A[x + y] = u + v;
                A[x + y + len] = u - v;
            }
        }
    }
    if (inverse) for (int i = 0; i < (1<<N); i++) A[i] /= (1<<N);
}

// In place and-transform. See and_convolution to understand its importance.
//   A'[x] = \sum_{x\subseteq y} A[y].
// Complexity: O(N*2^N).
template<typename T>
void and_transform(int N, T* A, bool inverse = false) {
    for (int len = 1; 2 * len <= (1<<N); len *= 2) {
        for (int x = 0; x < (1<<N); x += 2 * len) {
            for (int y = 0; y < len; y++) {
                if (inverse) A[x+y] -= A[x+y+len];
                else A[x+y] += A[x+y+len];
            }
        }
    }
}

// In place or-transform. See or_convolution to understand its importance.
//   A'[x] = \sum_{y\subseteq x} A[y].
// Complexity: O(N*2^N).
template<typename T>
void or_transform(int N, T* A, bool inverse = false) {
    for (int len = 1; 2 * len <= (1<<N); len *= 2) {
        for (int x = 0; x < (1<<N); x += 2 * len) {
            for (int y = 0; y < len; y++) {
                if (inverse) A[x+y+len] -= A[x+y];
                else A[x+y+len] += A[x+y];
            }
        }
    }
}

// C[x] = \sum_{y&z = 0, y|z = x} A[y]*B[z].
// Complexity: O(N*2^N).
template<typename T>
void subset_convolution(int N, const T* A, const T* B, T* C) {
    T** A_popcnt = new T*[N+1];
    T** B_popcnt = new T*[N+1];
    T* tmp = new T[1<<N];
    for (int i = 0; i <= N; i++) {
        A_popcnt[i] = new T[1<<N];
        B_popcnt[i] = new T[1<<N];
        clear(N, A_popcnt[i]);
        clear(N, B_popcnt[i]);
    }
    for (int x = 0; x < (1<<N); x++) {
        int q = __builtin_popcount(x);
        A_popcnt[q][x] = A[x];
        B_popcnt[q][x] = B[x];
    }
    for (int i = 0; i <= N; i++) {
        or_transform(N, A_popcnt[i]);
        or_transform(N, B_popcnt[i]);
    }
    for (int l = 0; l <= N; l++) {
        clear(N, tmp);
        for (int i = 0; i <= l; i++) {
            int j = l-i;
            for (int x = 0; x < (1<<N); x++)
                tmp[x] += A_popcnt[i][x]*B_popcnt[j][x];
        }
        or_transform(N, tmp, true);
        for (int x = 0; x < (1<<N); x++)
            if (__builtin_popcount(x) == l) C[x] = tmp[x];
    }
    for (int i = 0; i <= N; i++) {
        delete[] A_popcnt[i];
        delete[] B_popcnt[i];
    }
    delete[] A_popcnt;
    delete[] B_popcnt;
    delete[] tmp;
}

// B = exp(A).
//
// For x != 0, it holds
// B[x] = \sum_{0 < y_1 < y_2 < ... < y_k: y_i disjoint, y_1|y_2|...|y_k = x}
//                    A[y_1]*A[y_2]*...*A[y_k].
// The value B[0] is (arbitrarily) set to 1.
//
// The value of A[0] is disregarded.
template<typename T>
void exp(int N, const T* A, T* B) {
    B[0] = 1;
    for (int n = 0; n < N; n++) 
        subset_convolution(n, A + (1<<n), B, B + (1<<n));
}

// subset_convolution(A, C) = B.
//
// ACHTUNG: The value A[0] must be invertible.
template<typename T>
void inverse_subset_convolution(int N, const T* A, const T* B, T* C) {
    T inv = 1/A[0];
    
    T** A_popcnt = new T*[N+1];
    T** C_popcnt = new T*[N+1];
    for (int i = 0; i <= N; i++) {
        A_popcnt[i] = new T[1<<N];
        C_popcnt[i] = new T[1<<N];
        clear(N, A_popcnt[i]);
        clear(N, C_popcnt[i]);
    }
    for (int x = 0; x < (1<<N); x++) {
        int q = __builtin_popcount(x);
        A_popcnt[q][x] = A[x];
    }
    for (int i = 0; i <= N; i++) or_transform(N, A_popcnt[i]);
    
    for (int l = 0; l <= N; l++) {
        for (int i = 0; i <= l; i++) {
            int j = l-i;
            for (int x = 0; x < (1<<N); x++)
                C_popcnt[l][x] += A_popcnt[i][x]*C_popcnt[j][x];
        }
        or_transform(N, C_popcnt[l], true);
        for (int x = 0; x < (1<<N); x++) {
            int q = __builtin_popcount(x);
            if (q != l) C_popcnt[l][x] = 0;
            else {
                C_popcnt[l][x] = (B[x] - C_popcnt[l][x])*inv;
                C[x] = C_popcnt[l][x];
            }
        }
        or_transform(N, C_popcnt[l]);
    }

    for (int i = 0; i <= N; i++) {
        delete[] A_popcnt[i];
        delete[] C_popcnt[i];
    }
    delete[] A_popcnt;
    delete[] C_popcnt;
}

// exp(B) = A.
// The value of B[0] is (arbitrarily) set to 0.
//
// ACHTUNG: It must hold A[0] = 1.
template<typename T>
void log(int N, const T* A, T* B) {
    assert(A[0] == 1);
    B[0] = 0;
    for (int n = 0; n < N; n++)
        inverse_subset_convolution(n, A, A+(1<<n), B+(1<<n));
}

// A'[x] = A[complement of x]
template<typename T>
void complement(int N, T* A) {
    int pot = 1<<(N-1);
    for (int x = 0; x < pot; x++) swap(A[x], A[x|pot]);
}


// C[x] = \sum_{y^z = x} A[y]B[z]
// Complexity: O(N2^N).
template<typename T>
void xor_convolution(int N, const T* A, const T* B, T* C) {
    T* B2 = new T[1<<N];
    for (int x = 0; x < (1<<N); x++) C[x] = A[x], B2[x] = B[x];
    walsh_hadamard_transform(N, C);
    walsh_hadamard_transform(N, B2);
    for (int x = 0; x < (1<<N); x++) C[x] *= B2[x];
    walsh_hadamard_transform(N, C, true);
    delete[] B2;
}

// C[x] = \sum_{y&z = x} A[y]B[z]
// Complexity: O(N2^N).
template<typename T>
void and_convolution(int N, const T* A, const T* B, T* C) {
    T* B2 = new T[1<<N];
    for (int x = 0; x < (1<<N); x++) C[x] = A[x], B2[x] = B[x];
    and_transform(N, C);
    and_transform(N, B2);
    for (int x = 0; x < (1<<N); x++) C[x] *= B2[x];
    and_transform(N, C, true);
    delete[] B2;
}

// C[x] = \sum_{y|z = x} A[y]B[z]
// Complexity: O(N2^N).
template<typename T>
void or_convolution(int N, const T* A, const T* B, T* C) {
    T* B2 = new T[1<<N];
    for (int x = 0; x < (1<<N); x++) C[x] = A[x], B2[x] = B[x];
    or_transform(N, C);
    or_transform(N, B2);
    for (int x = 0; x < (1<<N); x++) C[x] *= B2[x];
    or_transform(N, C, true);
    delete[] B2;
}

}; // namespace internal

template<typename T>
struct SubsetFunction {
    int N;
    T* arr;
    SubsetFunction(int N): N(N) {
        arr = new T[1<<N];
        clear();
    }
    ~SubsetFunction() { delete[] arr; }
    SubsetFunction(const SubsetFunction& other) {
        N = other.N;
        arr = new T[1<<N];
        for (int x = 0; x < (1<<N); x++) arr[x] = other[x];
    }
    SubsetFunction& operator=(const SubsetFunction& other) {
        if (this != &other) {
            if (N != other.N) {
                N = other.N;
                delete[] arr;
                arr = new T[1<<N];
            }
            for (int x = 0; x < (1<<N); x++) arr[x] = other[x];
        }
        return *this;
    }
    T& operator[](int index) { return arr[index]; }
    const T& operator[](int index) const { return arr[index]; }
    void clear() { internal::clear(N, arr); }
};

#define CONVOLUTION_DEF(OP)                                         \
template<typename T>                                                \
SubsetFunction<T> OP##_convolution(const SubsetFunction<T>& A,      \
                                   const SubsetFunction<T>& B) {    \
    assert(A.N == B.N);                                             \
    SubsetFunction<T> C(A.N);                                       \
    internal::OP##_convolution(A.N, A.arr, B.arr, C.arr);           \
    return C;                                                       \
}

CONVOLUTION_DEF(xor)              // Complexity O(N2^N).
CONVOLUTION_DEF(and)              // Complexity O(N2^N).
CONVOLUTION_DEF(or)               // Complexity O(N2^N).
CONVOLUTION_DEF(subset)           // Complexity O(N2^N).
CONVOLUTION_DEF(inverse_subset)   // Complexity O(N2^N).

#define UNARY_OPERATOR_DEF(OP)                          \
template<typename T>                                    \
SubsetFunction<T> OP(const SubsetFunction<T>& A) {      \
    SubsetFunction<T> B(A.N);                           \
    internal::OP(A.N, A.arr, B.arr);                    \
    return B;                                           \
}

UNARY_OPERATOR_DEF(complement)    // Complexity O(N).
UNARY_OPERATOR_DEF(exp)           // Complexity O(N2^N).
UNARY_OPERATOR_DEF(log)           // Complexity O(N2^N).






template<typename T>
SubsetFunction<T> slow_subset_convolution(const SubsetFunction<T>& A,
                                          const SubsetFunction<T>& B) {
    int N = A.N;
    SubsetFunction<T> C(N);
    for (int x = 0; x < (1<<N); x++) for (int y = 0; y < (1<<N); y++) {
        if (x&y) continue;
        C[x|y] += A[x] * B[y];
    }
    return C;
}


template<typename T>
SubsetFunction<T> slow_or_convolution(const SubsetFunction<T>& A,
                                      const SubsetFunction<T>& B) {
    int N = A.N;
    SubsetFunction<T> C(N);
    for (int x = 0; x < (1<<N); x++) for (int y = 0; y < (1<<N); y++) {
        C[x|y] += A[x] * B[y];
    }
    return C;
}


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define int  long long


const int M = 2e15 + 1;

int largest_bit(int x) {
    return 31 - __builtin_clz(x);
}
 

int solve(){
 		int n; cin >> n;
 		vector<int> a(n),b;
 		for(auto &i:a)cin >> i;
 		for(auto i:a){
 			//i = b.size() + 1; 
 			if(i != 0)b.push_back(i);
 		}
 		swap(a,b);
 		n = sz(a);
 		SubsetFunction<short> s(n);
 		bool found = 0;
 		for(int mask = 1; mask < (1 << n); mask++){

 			int sum = 0;
 			int cnt = 0;
 			vector<int> vals;
 			for(int j = 0; j < n; j++){
 				if((1 << j) & mask){
 					vals.push_back({a[j]});
 					sum += a[j];
 					cnt++;
 				}
 			}
 			if(cnt == 1)continue;
 			if(abs(sum) % 2 != cnt % 2){
 				int m = cnt/2;
 				int k = cnt - m;
 				vector<int> v1(1 << m),v2(1 << k);
 				for(int j = 0; j < (1 << m); j++){
 					for(int l = 0; l < m; l++){
 						if((1 << l) & j)v1[j] += vals[l];
 						else v1[j] -= vals[l];
 					}
 				}

 				for(int j = 0; j < (1 << k); j++){
 					for(int l = 0; l < k; l++){
 						if((1 << l) & j)v2[j] += vals[l + m];
 						else v2[j] -= vals[l + m];
 					}
 				}
 				int count = 0;
 				if(abs(sum) <= cnt - 1)count -= 2;
 				sort(v1.begin(),v1.end());
 				sort(v2.begin(),v2.end());
 				for(auto i:v1){
 					//i + j <= cnt - 1
 					//i + j >= 1 - cnt
 					int l = 1 - cnt - i;
 					int r = cnt - i - 1;
 					


 					count += upper_bound(all(v2),r) - lower_bound(all(v2),l);
 					if(count > 0)break;
 				}
 				if(count > 0)s[mask] = 1,found = 1;
 			}
 		}
 		if(!found){
 			cout << n << endl;
 			return 0;
 		}
                
                vector<int> dp(1 << n,0);
                for(int mask = 1; mask < (1 << n); mask++){
                        dp[mask] = s[mask];
                        int smaller = mask - (1 << largest_bit(mask));
                        for(int sub = smaller; sub; sub = (sub - 1) & smaller){
                                maxs(dp[mask],dp[mask^sub] + s[sub]);
                        }
                }
                cout << n - dp.back() << endl;

 return 0;	
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}