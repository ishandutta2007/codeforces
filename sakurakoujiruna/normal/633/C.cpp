#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100011;

struct Trie
{
	struct Node
	{
		Node *nxt[52];
		int sid;
		Node()
		{
			memset(nxt, 0, sizeof(nxt));
			sid = -1;
		}
	}*root;
	Trie() { root = new Node(); }
	void insert(const string &str, int sid)
	{
		Node *p = root;
		for(auto &c : str)
		{
			if(p -> nxt[c - 'a'] == NULL)
				p -> nxt[c - 'a'] = new Node();
			p = p -> nxt[c - 'a'];
		}
		p -> sid = sid;
	}
	vector <int> query(const string &str)
	{
		//cout << str << '\n';
		vector <int> res;
		Node *p = root;
		for(auto &c : str)
		{
			if(p -> nxt[c - 'a'] == NULL)
				break;
			p = p -> nxt[c - 'a'];
			if(p -> sid != -1)
				res.push_back(p -> sid);
		}
		return res;
	}
}trie;

bool dp[N];
int from[N];
string str[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	string text;
	cin >> text;
	int m;
	cin >> m;
	for(int i = 0; i < m; i ++)
	{
		cin >> str[i];
		string tmp = str[i];
		reverse(tmp.begin(), tmp.end());
		for(auto &c : tmp)
			if(c >= 'A' && c <= 'Z')
				c = c - 'A' + 'a';
		trie.insert(tmp, i);
	}
	dp[0] = true;
	for(int i = 0; i < n; i ++)
		if(dp[i])
		{
			string tmp = text.substr(i, 1000);
			vector <int> trans = trie.query(tmp);
			for(auto &sid : trans)
			{
				from[str[sid].size() + i] = sid;
				dp[str[sid].size() + i] = true;
			}
			//cout << i << '\n';
		}
	vector <int> ans;
	int p = n;
	while(p > 0)
	{
		ans.push_back(from[p]);
		p -= str[from[p]].size();
	}
	reverse(ans.begin(), ans.end());
	for(auto &sid : ans)
		cout << str[sid] << ' ';
	cout << '\n';
	return 0;
}