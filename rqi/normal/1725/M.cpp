#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
// #include <cuchar>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
// #include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
// #include <memory_resource>
#include <string_view>
#include <variant>
#endif

#if __cplusplus > 201703L
#include <barrier>
#include <bit>
#include <compare>
#include <concepts>
#if __cpp_impl_coroutine
# include <coroutine>
#endif
#include <latch>
#include <numbers>
#include <ranges>
#include <span>
#include <stop_token>
#include <semaphore>
#include <source_location>
#include <syncstream>
#include <version>
#endif

using namespace std;

using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

const int MOD = 1e9+7;
const ll BIG = 1e18;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
    return b < a ? a = b, 1 : 0;
}
tcT> bool ckmax(T& a, const T& b){
    return a < b ? a = b, 1 : 0;
}

const int mx = 200005;
vector<pair<int, ll>> adj[mx][2];
ll dist[mx][2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        int U, V, W;
        cin >> U >> V >> W;
        adj[U][0].pb(mp(V, W));
        adj[V][1].pb(mp(U, W));
    }
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 2; j++){
            dist[i][j] = BIG;
        }
    }
    priority_queue<pair<ll, pair<int, bool>>, vector<pair<ll, pair<int, bool>>>, greater<pair<ll, pair<int, bool>>>> pq;
    ckmin(dist[1][0], 0LL);
    pq.push(mp(dist[1][0], mp(1, 0)));
    while(sz(pq)){
        ll d = pq.top().f;
        int node = pq.top().s.f;
        int dir = pq.top().s.s;
        pq.pop();
        if(dist[node][dir] != d) continue;
        for(auto u: adj[node][dir]){
            if(ckmin(dist[u.f][dir], d+u.s)){
                pq.push(mp(dist[u.f][dir], mp(u.f, dir)));
            }
        }
        if(dir == 0){
            if(ckmin(dist[node][1], d)){
                pq.push(mp(dist[node][1], mp(node, 1)));
            }
        }
    }
    for(int i = 2; i <= N; i++){
        if(dist[i][1] == BIG) dist[i][1] = -1;
        cout << dist[i][1];
        if(i+1 <= N){
            cout << " ";
        }
    }
    cout << "\n";
}