#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) for(int i = 0; i < a; i++)
#define EB emplace_back
#define ST first
#define ND second

using LL = long long;
using PII = pair<int, int>;

template<class L, class R> ostream& operator<<(ostream &ost, pair<L, R> p)
{
	return ost << "(" << p.ST << ", " << p.ND << ")";
}

template<class T> ostream& operator<<(ostream &ost, vector<T> &vec)
{
	ost << "{";
	REP(i, vec.size()) ost << (i == 0 ? "" : ", ") << vec[i];
	return ost << "}";
}

template<class T> void dump(const char *s, T a) { cerr << s << ": " << a << "\n"; }
template<class T, class... TS> void dump(const char *s, T a, TS... x)
{
	while(*s != ',') cerr << *s++;
	cerr << ": " << a;
	dump(s + 1, x...);
}

#ifdef DEBUG
#define DB(...) dump(#__VA_ARGS__, __VA_ARGS__)
#else
#define DB(...)
#endif

struct str
{
	int id, cnt;
	char last;
};

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n;
	cin >> n;


	auto is_vowel = [&](char c)
	{
		for(char vowel : "aeiou")
			if(vowel == c)
				return true;
		return false;
	};

	vector<string> data(n);
	vector<str> strings(n);
	REP(i, n)
	{
		string s;
		cin >> s;
		data[i] = s;

		strings[i].id = i;
		for(char c : s)
		{
			if(is_vowel(c))
			{
				strings[i].cnt++;
				strings[i].last = c;
			}
		}
	}

	sort(strings.begin(), strings.end(), [&](str i, str j)
	{
		if(i.cnt != j.cnt) return i.cnt < j.cnt;
		return i.last < j.last;
	});

	vector<PII> matches;
	vector<bool> removed(n);
	FOR(i, 1, n - 1)
	{
		if(!removed[strings[i - 1].id] && strings[i].cnt == strings[i - 1].cnt && strings[i].last == strings[i - 1].last)
		{
			matches.EB(strings[i - 1].id, strings[i].id);
			removed[strings[i - 1].id] = true;
			removed[strings[i].id] = true;
		}
	}

	sort(strings.begin(), strings.end(), [&](str i, str j)
	{
		if(removed[i.id]) return false;
		if(removed[j.id]) return true;
		return i.cnt < j.cnt;
	});
	

	vector<PII> rest;
	FOR(i, 1, n - 1)
	{
		if(!removed[strings[i].id] && !removed[strings[i - 1].id] && strings[i].cnt == strings[i - 1].cnt)
		{
			rest.EB(strings[i - 1].id, strings[i].id);
			removed[strings[i].id] = true;
			removed[strings[i - 1].id] = true;
		}
	}

	DB(matches, rest);

	vector<string> ans;
	while(!matches.empty())
	{
		PII second = matches.back();
		matches.pop_back();
		PII first;
		if(!rest.empty())
		{
			first = rest.back();
			rest.pop_back();
		}
		else
		{
			if(!matches.empty())
			{
				first = matches.back();
				matches.pop_back();
			}
			else
				break;
		}

		string lyric = data[first.ST] + " " + data[second.ST] + "\n" + data[first.ND] + " " + data[second.ND];
		ans.EB(lyric);
	}

	cout << ans.size() << "\n";
	for(string s : ans)
		cout << s << "\n";
}