#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt,tune=native")
//#pragma comment(linker,"/STACK:256777216")
/*
MMMMMMMMNNNNNNNNNNNNNNNNNNmNNNNNNNNNNNmmmmmmmmNNMMMMNMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMNNMMMNMMMMMMMMMMMMMMMMMMMMMMNNMMNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMNNNNNNNNNNNmNNNMMMMMMMMMMMMNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMNNNNNNNNNNNNNNNNmmNNNNNNNNMMMMMMMMNmNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMNNNNNMMNNNNNNNNNNNNNNNNNNNNNMMMMMMMMNmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMNNNNNMMNNNNNNmNNNNNNNMMMMMMMMMMMMMMMMNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMNNNNNNNNNNNNNmNNNNNNNNNNMMMMMMMMMMMMMMmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMNNNNNNNNNNNNNmNNNmNMMMMmMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMNNNNNNNNNNmmmmmNNNNMMNMMNNMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
NNNNNNNNNNNmmmmdddddmNNNNMNNMMNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMNNMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
NNNNNNNNNmmmddddhhhdNNNmmMMMMNmmNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMNMMMMMMMMMNMMMMMMMMMMMMMMMNMMNMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
NNNNNNNNmmddddhhhhhdmNNmNmNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMNMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMNMMMMMMMMMMMMMMMNMMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM
NNNNNNNmmddddhhhhhhhdNNmNNNNNNNNmmNNNNNNNNNNMMMMMMMMMMMMNMMNMMMMNMMMMMNMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMMMMMMMMNMMMMMMMMMMMMMMNMNMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMMM
NNNNNNNmddhhhhhhhyyyhmmNmmmNNMMMMNmNNNNNNNNNMMMMMMMMMMMNMMMNMMMMNMMMMNNMMMMNMMMNMMMMMMMMMMMMMMMMNMMNMMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMNNMMMMMNMMMMMMMMMMMMMMMMMMMMMMMMMMM
NNNNNNmdhhhhhhyyysssshmdmNMMNNNNNNNmmmmmmmmMMMMMMMMMMMMNMMMNMMMMMMMMMNNMMMMNMMMNMMMMMMMMMMMMMMMMNMMNMMMNMMMNMMMNMMMMMMMMNMMMMMMMMMMMMMMNMMMMMMNNNNNNNNNMMNNNNNNNNNNNNNNNMM
MNNNNmdhyyyyyyysssssssdNNNNNNNNNNNNNNNNNNNmMMMMMMMMMMMMNMMMNMMMNMMMMMNNMMMMNMMMMMMMMMMMMMMMMMMMMNMMNMMMNMMMNMMMMNMMMMMMMNNNNMMMMMMMMMMMNMMMMMMMmmmmmNNNNmmmmmmmmmmmmmmmNNN
MMNNmmdhsoooooooooooooohmNNNNNNNNNNNNNNNdNNMMMMMMMMMMMMNMMMNMMMNNMMMMNMNMMMNMMMMNMMMMMMMMMMMMMMMNMMNMMMNMMMNMMMMMNMMMMMMNNNMNNNMMMMMMMNmMMMMMMMmdddmmmdddddddddddddddddmmN
MNNmmmdhsooooooooooo++ooshmNNNNNNNNNNmhysNNMMMMMMMMMMMNNMMMNMMMNNMMMMNMNMMMNMMMMNMMMMMMMMMMMMMMNMMNMMMNMMMMNNNMMMNMMMMMMNNNMMMMNNMMNNNMdMMMMNMMNmddddddddddddhhhhhhhhddmmN
NmmddddhhhhhhhhhhhhyyyyyyyyhdddmmdddhsoosdNMMMMMMMMMMMNNMMMNMMMNNMMNNmNNMMMNNMMMNMMMMMMMMMMMMMMNMMNMMMNMNNmNMMMMMMNMMMMMMNNNMMmNNNNMMMMmNMMMNNMNmNNNNNNNNNNNmmmmmmmmmNNNMM
mmdddddddddddddddddddhhyyyyyyyhhhyyyoooosdNMMMMMMMMMMMNNMMMNMMMNNMMMMNMNmNNMNMMMNMMMMMMMMMMMMMNNMNNMMNNNNNNMMMMMMMMNMMMMMNMMNMMmNNMmmMmNNMMMMNMMNNNNNNNNNNNNNNNNNNNNNNMMMM
mmddddhdddddddddddddddhhhyyyhhhysssoooosshNMMMMMMMMMMMNNMMMNMMMNNMMMMNMMNMMNNmNNNmMMMMMMMMMMMMNMNmNNNNMMMNMMMMMMMMMMNMMMMNMMMNNMMMMNMNNMNMMMMNNMNNNNNNNNNNNNmmmNNNNNNMMMMM
dddddhhhdddddddddddddddhhhhhhysosyoooosmsyNMMMMMMMMMMMNNMMMNMMMMNNMMMdMNNNMMMNNMMmNMMMMMMMMMMNMMNNMMNMMMNNNMNMMMMMMMMNMMMNMMNNNNNMMMmNMMNMMMMMNNNNNNNNNNNNNNmmNNNNNNMMMMMM
dddddhhhddddddddddddddddhhhsoosyhooooodNssNMMMMMMMMMMMNNNMMNNMNmdhhysshmNNNNNMNNMNmMMMMMMMMMNNMNNMMNNNNmNNNmyhddmmNMMMNMMNMNmMNdNMMmNmNMNMMMMMNmMmNNNNNNMMNNNNNNNMMMMMMMMM
dddddhhhddddddddddddddddysoooyhho++o+sNmosNMMMMMMMMMMMNNNMNdyhhhho////oyssydmmMNNMNNMMMMMMMMNMMNMMMNNNmdhyso++oosssyddNNNNMmMMNMNmNNmMmNmMMMMMMmmNmNNNNNNNNNNNNMMMMMMMMMMM
hdddhhhhhhhddddddddddddsoooyhhho++ssodNmosMMMMMMMMMMMMmNmhddmNMNNy/////+mmy/hNMMMMMMMMMMMMMMMMMMMMMMNmsohdo:::::+mNNdhhmNNNNMMNmNNmNMMNmmMMMMMMNdNmmNNNNNNNNNNMMMMMMMMMMMM
hhhhhyyyhhhhhdddddddddh++shhhho++shooNMdoyMMMMMMMMMMMMmMNdMMMMN+yy+sss++oMMdsmMMMMMMMMMMMMMMMMMMMMMMmyhNhmh+oo++:+MMMMNdNmmNNNNNMMNNmNMdmNMMMMMMNdNmNNNNNNNNMMMMMMMMMMMMMM
hhhhhyyyyhhhhhddddddddy++hhhhs+/+ys+hNNyoyNMMMMMMMMMMMNMMNNMMMh-oshdddyy+NMMNhMMMMMMMMMMMMMMMMMMMMMMdNMM+/yyddhss:NMMMMNMmNMMMMMMMMMNmmdNNNMMMMMNmmNmmNNNMMMMMMMMMMMMMMMMM
hhhhyyyyyyyhhhhddddddhs++hhhy+/:+o+smNNoodMMMMMMMMMMMMNMMMmMMMh-yydhddhhoNMMMNMMMMMMMMMMMMMMMMMMMMMMMMMM/oyddddydoNMMMmNMNMMMMMMMMMMMNNmNNNNNNNNNNdmmmNNNMMMMMMMMMMMMMMMMM
hhhhyyyyyyyhhhhddddddhs++yyo+++///ohNNs+dmNNNNNNNMMMMNNMMMNmMMN/+dhdmmhmhMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMs+hhddhdmmMMMNNMMNNNNNNNNNNNNNNNNNNNNNNNNNmmNmNNMMMMMMMMMMMMMMMMMM
hhhyyyyyyyyhhhhhhhhdhhy//o+/+s////yhNy+yNmNNNNNNNNNNNNNMMMMNNMMNoodNNNdsmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNohNNNmdyNMMNNMMMNNNNNNNNNNNNNNNNNNNNNNNNNmmmNmMMMMMMMMMMMMMMMMMMM
hhhyyyyyyyyyhhhhhhhhhhh+//+sho/::/hhs+yNNmNNNNNNNNNNNNNMMMMMNNNNNmhdmddMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmdmmmmNNNNNNNNNmNNNNNNNNNNNNNNNNNNNNNNNNNmNmmNMMMMMMMMMMMMMMMMMM
hhhyyyyyhyyhhhhhhhhhhhhhhhhhh+/://+/+hNNNmNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNmNNNNNNNNNNNNNNNmNNNNNNNNNmNNmmMMMMMMMMMMMMMMNMMM
hhyyyyyyhhhhhhhhhhhhhhhhhhhho:/os//smNNNNmNNNNNNNNNNNNmNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMNNMMMMMMMMMMMMMMMMMMMNNNNNNNNNNMNNmNNNNNNNNNNNNNNNmNNNNNNNNNNmNmmmMMMMMMMMMMNNMMMMM
hyyyyyyyhhhhhhhhhhhhhhhhhhho://hhyyNNNNNNmNNNNNNNNNNNNmNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMNmMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNdNNNNNNNNNNNNNNNmNNNNNNNNNNmMMmmNMMMMMMMMNNNMMMMM
yyyyyyyhhhhhhhhhhhhhhhhhhho/:/+hhhhNNNNNmmNNNNNNNNNNNNmNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMNNNNNNNNNNNmmmdNNNNNNNNNNNNNNmmNNNNNNNNNNmNMMmmNMMMMMMMMMMMMMMM
yysyyyyhhhhhhhhhhhhhhhhhho::::ohhhdNNNNNmmNNNNNNNNNNNNmNNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNmdNNNNNNNNNNNNNNmmNNmNNNNNNNNmMMNmmNMMMMMMMMMMMMMM
yssyyyyhhyyyyyhhhhhhhhhyo:/o::shhhdNNNNmNmNNNNNNNNNNNNyNNNNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNmsNNNNNNNNNNNNNNmmNNmNNNNNNNNmNNNmmmNNMMMMMMMMMMMN
ssssssyyysssyyyyyyyyyyy+:/so::syyymNNNmmNdNNNNNNNNNNNNhdNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNhsNNNNNNNNNNNNNNmNNNdNNNNNNNNmddddhmdNNNNNMNNNNNNN
oo++++oooooossssssssso/:/os/::+oosNNNNdNNdNNNNNNNNNNNNhymNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNmyyNNNNNNNNNNNNNNmNNNdNNNNNNNNmyyyhhhmdmmmNNmmmmddd
++////++oosssssssssso::/sss:::+++yNNNdNNNdNNNNNNNNNNNNhhyNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNyyyNNNNNNNNNNNNNNdNNNmmmmmmmmmmhdhddddmdddddddhhhhh
////////+ossyysysss+::/ssss::+ssshmNmmNNNdNNNNNNNNNNNNhhhhNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNhhhymNNNNNNNNNNNmmdmmmmdmmmmmmmmdddddmddhddhhhhhhhhh
//:::--:/+ssyyyyys/--+ssssy:-+sssmmmdmmNmdNNNNNNNNNNNNyyhyyNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNhyhhymNNNmmmmmmmmmmymmmmdmmmmmmmmdhhddddhdyhhhhhhhhhh
///::---/+osssyys/--+ssyysy--+sssmmdmmmmmdmmmmmNmNNNmmhssyyymNNNNNNNNNNNNNNNNNNNNNmmmNmmNNmmmmmNNNNNNNNNNNNNNNNNNNNNhssyssmmmmmmmmmmmmmmydmmmhmmmmmmmmdhdddddhhdyyyyhhhhhh
///::--:/+osssss:-:osssssys--+ssymdmmmmdmhmmmmmmmmmmmmhyyyyyohmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNdyssssssmmmmmmmmmmmmmmshmmmhmmmmmmmddhddddhhyhhyyyyhhhhh
///::--:/osssso--:ssssssyys--+ssyddmmmdmmhmmmmmmmmmmmmhsssssosshmNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNdyssssssssmmmmmmmmmmmmmmsymmmhdddddddddyddhhhhhhhyyyyhhhhh
///::--:/osss+--:sssssssyss--+soydmmmhmmmhmmmmmmmmmmmmhsssssossssydNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmhsssssosssssmmmmmmmmmmmmddosdddhdddddddddyhhhhhhyyyhsyyhhhhh
////:--:+oss/--/sssssssyyss--+sohdddhddddddmmmmmmmmmmmysssssosssssoshNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNdyosossssosssssddmddddddddddhoodddhhddddddddydhhhyyyyyysyyhhhhh
////:::/+os/../ssssssssysss--/osddddhdddddhdddddddddmdyssssoosssssoossydNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmysosssoossooooooodddddddddddddsoohdddyddddddhhyhhhhhyyyhsyshddddd
////:::/+o/../sssssssssssss--:sddddyddddddhdddddddddddyooooooooooooooo+syhmmmmmmmmmmmmmmmmmmmmmmmmmmmmhyy+oooooooooo+ooooodddddddddddddooohddhshhhhhhhhhyhhhhhhhhhssdmmmmm
++//:::/+/../sssssssssyssss--:hhddyhhdddddydddddddddddyoooooooooooo+oo+yyysydmmmmmmmmmmmmmmmmmmmmmmdyyyys+oooooo+ooo+oooosdddddddddddhhoo+yhhhshhhhhhhhhshhhhhyyyysyyddddd
++//::://../ssyyyyyysyyssss:.-hhhhyyhhdddyyhddddddddddyoooo+ooooooo+oo+sssysssyhdmmmmmmmmmmmmmmdhysssssso+oooooo+ooo+ooooshdddhhhhhhhhy+++yhhyohhhhhhhhhsyyyyysssysosyyhhh
+++/:://..:ssyyyyyyyyyyyyss/.-hhhsyyhhhhhyhyhhhhhhhddhyoooo+ooooooyhhyosssssssssssyhdmmmmmmdhyssssssssssoooo+ooo+o+++++++shhhhhhhhhhhhs+++shhsshhhhyyyyyossssssssyyosoyyhh
+++////..-ossyyyyyyyhyyyyyy+..shyyshhhhhhyhshhhhhhhhhhy++++++++ooddddddhssssssssssssssyhhysssssssssssoyhdddhyo++/++++++++shhhhhhhhhhhy++++syysoyyyyyyyyyosssssssssysooyyhh
+++///-..+ossyyyyyyyhhhhyyss..oyssyhhhhhhyhshhhhhhhhhhy++++/++++++/:/oyddyossssssssssssossssssssssssoydho+++sy++/++/+++++yhhhhhhhhhyys/+//syyooyyyyyyyyyosssssssssysossyhh
+++//-../ooossyyyyyyyhyyysyy-.:oysyyyyyyyyysyhhhhhhhhhy++++/++++--+oo/-+hdyssyyyyssoooooooooooossssshds--///::://++/++++/yyyyyyyyyyyy+////oyyooyyyyyyyysosssssssssyysooyyh
++++/...+ooossyyyyyyyyyyssyy/..ooyyyyyyysyyysyyyyyyyyyy+++//++++:yhddhs-:yhhhhhhhddhooooooooyhhhhhhhho-+hhhhhy://///////+yyyyyyyyyyys/////oyssoyssssssss+ssssssssssyy+osyy
////.``/+++ossyyyyyyyyyyosss+..+oyyyyyyyoyyysyyyyyyyyyy//////////yhhhhhy--:---:://shh+oooo+yhhs/:::::-+hhhhhh+//////////+yyyyyyyyyyyo/////osoyosssssssss+ssssssssyyyyoooyy
/::-``-///++oossssssyyyosssso..-ssssyyyyoyyyssyyyyyyyyy//////////ohhhhhhyssoooo+:..+hy+oo+yhy:.:oyhhyshhhhhyo://////////+yyyyyyyysss/////:osohosssssssss+yyyyyyyyyhhhhoohh
:::.``::://+++o++o++oo+osssss-.-ssssssssossssossssyyyyy+o+////////hhhhhhhhhhhhhhhs-.sy++++hs-.ohhhhhhhhhhyo+/:/:/://////osssssssssso::::::ssshossssssooooyyyyyyhhhhdmmo+hh
//:--:////+++oo+++///++osssss:.-ooosssssossssosssosssysossyyssossossyyyyyyyyyyyyyyo-/so+/ss:-oyyyyysyyyyy++/-:::////++o+osossssssss///////ooos+ooooooooo+syyyyyyyyyyddo+yh
*/


#include <set>
#include <map>
#include <deque>
#include <string>
#include <cstdint>
#include <cmath>
#include <queue>
#include <cassert>
#include <random>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <time.h>//////////////
#include <ctime>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <complex>
#include <chrono>
#include <unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define pbc push_back
#define pob pop_back()
#define vin(a) for (auto& i : a) cin >> i
#define sp system("pause")
#define mp make_pair
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y)
{
	if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y)
{
	if (x < y) x = y;
}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
ld asdasdcl = 0;
double getTime() { return (clock() - asdasdcl) / (double)CLOCKS_PER_SEC; }
/*
#define getchar_unlocked _getchar_nolock
inline int readInt()
{
	char x;
	while (x = getchar_unlocked())
	{
		if (x >= '0' && x <= '9')
		{
			int ans = x - '0';
			while (x = getchar_unlocked())

			{
				if (!(x >= '0' && x <= '9')) return ans;
				ans = ans * 10 + x - '0';
			}
		}
	}
}*/
/*using namespace __gnu_pbds;

using ordered_set = tree<
	pair<int, int>,
	null_type,
	less<pair<int, int>>,
	rb_tree_tag,
	tree_order_statistics_node_update>;*/
const int inf = 1e9 + 228;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
const int mod = 1000000007;
const ld INF = 1e18;
const int MAXN = 5e5 + 228;
int f[MAXN];
void add(int r, int x)
{
	for (; r < MAXN; r |= (r + 1))f[r] = max(f[r], x);
}
int get(int r)
{
	int ans = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1) ans = max(ans, f[r]);
	return ans;
}
vector<pair<int,int>> is;
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int n;
	cin >> n;
	vector<int> b(n), ii(n), r(n);
	vin(b);
	vin(ii);
	vin(r);
	for (int i = 0; i < n; ++i)
	{
		is.pbc({ -ii[i],-ii[i] });
	}
	sort(all(is));
	is.resize(unique(all(is)) - is.begin());
	vector<int> ids(n);
	iota(all(ids), 0);
	sort(all(ids), [&](int a, int y)
		{
			return tie( b[a], ii[a], r[a] ) < tie(b[y], ii[y], r[y]);
		});
	int res = 0;
	for (int i = ids.size() - 1; i >= 0; --i)
	{
		int j = i;
		while (j - 1 >= 0 && b[ids[j - 1]] == b[ids[i]])--j;
		for (int x = i; x >= j; --x)
		{
			int tii = lower_bound(all(is), mp(-ii[ids[x]], -ii[ids[x]])) - is.begin();
			int jj = get(tii -1);
			if (jj > r[ids[x]])
			{
				++res;
			}
		}
		for (int x = i; x >= j; --x)
		{
			int tii = lower_bound(all(is), mp(-ii[ids[x]], -ii[ids[x]])) - is.begin();
			add(tii, r[ids[x]]);
		}
		i = j;
	}
	cout << res;
	//sp;
}