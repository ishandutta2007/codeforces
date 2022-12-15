#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
const int inf = 1e9;

int fail_links[N];

void build_fail_links(string word)
{
	fail_links[0]  = 0;

	for(int i = 1; i < word.size(); i ++)
	{
		fail_links[i] = fail_links[i-1];

		while(fail_links[i] > 0 && word[i] != word[fail_links[i]])
			fail_links[i] = fail_links[fail_links[i] - 1];

		if(word[i] == word[fail_links[i]])
			fail_links[i] ++;
	}
}

void kmp(string text, string word, int arr[])
{
	build_fail_links(word);

	int start = 0, match = 0;
	int i = 1;

	for(int j = 1; j <= word.size(); j++)
		arr[j] = inf;

	while(true)
	{
		while(start + match < text.size() && match < word.size() && word[match] == text[start + match])
			match ++;

		for(i; i <= match; i++)
			arr[i] = start + i;

		//cout << start << " " << match << endl;

		if(start + match >= text.size() || match >= word.size())
			break;

		match = max(match - 1, 0);

		start += match - fail_links[match] + 1;
		match = fail_links[match];
	}
}

int when_1[N], when_2[N];

bool solve(string text)
{
	string word;

	cin >> word;

	kmp(text, word, when_1);

	reverse(text.begin(), text.end());
	reverse(word.begin(), word.end());

	kmp(text, word, when_2);

	//for(int i = 0; i <= word.size(); i++)
	//	cout << when_1[i] << ", " << when_2[i] << " " << i << endl;
	//cout << endl;

	for(int i = 1; i < word.size(); i++)
		if(when_1[i] + when_2[word.size() - i] <= text.size())
			return true;

	return false;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string text;

	cin >> text;

	int m, res = 0;

	cin >> m;

	for(int i = 0; i < m; i++)
		res += solve(text);

	cout << res << "\n";

	return 0;
}