#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

const long long N = 1e5 + 7;
const long long ones = (long long)((1ll << 45) - 1);

long long a[N];

struct trie
{
	trie* up[2];

	trie()
	{
		up[0] = nullptr;
		up[1] = nullptr;
	};
};

trie* root = new trie();


void putInMap(long long x)
{
	trie* curr = root;

	for(long long i = 44; i >=0; --i)
	{
		if(curr -> up[(bool)(x & (1ll<<i))] == nullptr)
			curr -> up[(bool)(x & (1ll<<i))] = new trie();

		curr = curr -> up[(bool)(x & (1ll<<i))];
	}
}

long long searchInMap(long long x)
{
	long long res=0;
	trie* curr = root;

	for(long long i = 44; i >= 0; --i)
	{
		//cout<<x<<" "<<i <<" = "<<res<<endl;

		if(curr -> up[(bool)(x & (1ll<<i))] == nullptr)
		{
			curr = curr -> up[(bool)!(x & (1ll<<i))];
			if(!(x & (1ll<<i)))
				res += 1ll<<i;
		}
		else
		{
			curr = curr -> up[(bool)(x & (1ll<<i))];
			if((x & (1ll<<i)))
				res += 1ll<<i;
		}
	}

	return res;
}

int main ()
{
	long long n, curr = 0, res = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(long long i = 0; i < n; ++i)
		cin >> a[i];

	putInMap(0ll);

	for(long long i = 0; i < n; ++i)
	{
		curr ^= a[i];

		putInMap(curr);
	}

	curr = 0;

	for(long long i = n-1; i >= 0; --i)
	{
		curr ^= a[i];

		//cout << searchInMap(curr ^ ones) << endl;


		res = max(searchInMap(curr^ones) ^ curr, res);
	}

	cout<<res<<"\n";

	return 0;
}