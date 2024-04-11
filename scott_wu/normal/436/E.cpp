#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 600100;

int N, W;
vector <pair <ll,int> > os;
vector <pair <pair <ll, ll>, int> > t2;

ll bval[MAXN];
ll mval[MAXN];
int msource[MAXN];
int source[MAXN];
int ans[MAXN];

inline bool cmp (pair <ll, ll> left, pair <ll, ll> right)
{
	return left.first + left.second < right.first + right.second;
}

inline bool cmp2 (pair <pair <ll, ll>, int> left, pair <pair <ll, ll>, int> right)
{
	return cmp (left.first, right.first);
}

int main()
{
    cin >> N >> W;
    for (int i = 0; i < N; i++)
    {
        ll a, b; cin >> a >> b;
        b -= a;
        if (a <= b)
        {
            os.push_back (make_pair (a, i)); os.push_back (make_pair (b, i));
        }
        else
        {
            t2.push_back (make_pair (make_pair (a, b), i));
        }

        //cout << a << " " << b << "\n";
    }

	sort (os.begin(), os.end());
	sort (t2.begin(), t2.end(), cmp2);

	int M = t2.size();
	//cout << M << "\n";

	for (int i = 0; i <= W; i++)
		bval[i] = 1e15;
	
	if (M > 0)
	{
		mval[M-1] = t2[M-1].first.first;
		msource[M-1] = M-1;
	}
	for (int i = M - 2; i >= 0; i--)
	{
		if (t2[i].first.first < mval[i+1])
			msource[i] = i;
		else
			msource[i] = msource[i+1];
		mval[i] = min (mval[i+1], t2[i].first.first);
	}

	ll tot = 0, mhi = -1e9;
	int mloc = -1;
	bval[0] = 0;

	for (int i = 0; i < M; i++)
	{
		if (tot + mval[i] < tot + t2[i].first.first + t2[i].first.second - mhi)
			source[2*i+1] = msource[i];
		else
			source[2*i+1] = mloc;
		bval[2*i+1] = min (tot + mval[i], tot + t2[i].first.first + t2[i].first.second - mhi);
		tot += t2[i].first.first + t2[i].first.second;

		if (t2[i].first.second > mhi)
			mloc = i;
		mhi = max (mhi, t2[i].first.second);
		bval[2*i+2] = tot;
	}

	//cout << M << "\n";

	int res = max (0, W - (int) os.size());
	for (int i = max (0, W - (int) os.size()); i < W; i++)
	{
		if (bval[i+1] < bval[i] + os[W-1-i].first)
			res = i+1;
		
		bval[i+1] = min (bval[i+1], bval[i] + os[W-i-1].first);
	}

	for (int i = 0; i < MAXN; i++)
		ans[i] = 0;
	for (int i = 0; i < W - res; i++)
		ans[os[i].second]++;

	for (int i = 0; i < res / 2; i++)
		ans[t2[i].second] += 2;
	if (res % 2 == 1)
	{
		int c = source[res];
		if (c >= res/2)
			ans[t2[c].second]++;
		else
		{
			ans[t2[c].second]--;
			ans[t2[res/2].second] += 2;
		}
	}
	
	cout << bval[W] << "\n";
	for (int i = 0; i < N; i++)
		cout << ans[i];
	cout << "\n";
	return 0;
}