#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > sol;
int ans;

struct node
{
	vector<int> a[2];
	node* ch[26];
	node* par;
	int dep;
	node(node* P, int D)
	{
		for (int i = 0;i < 26;i++)
			ch[i] = NULL;
		par = P;
		dep = D;
	}
	void upd(char* buf, int idx, int lid, int sid)
	{
		if (buf[idx] == 0)
		{
			a[lid].push_back(sid);
			return;
		}
		if (ch[buf[idx]-'a'] == NULL) ch[buf[idx]-'a'] = new node(this, dep+1);
		ch[buf[idx]-'a']->upd(buf, idx+1, lid, sid);
	}
	void solve()
	{
		for (int i = 0;i < 26;i++) if (ch[i] != NULL)
			ch[i]->solve();
		while (a[0].size() && a[1].size())
		{
			ans += dep;
			sol.emplace_back(a[0].back(), a[1].back());
			a[0].pop_back();
			a[1].pop_back();
		}
		for (int i = 0;i < 2;i++) for (int u: a[i])
			par->a[i].push_back(u);
	}
};

char buf[800005];
node* root;
int n;

int main()
{
	root = new node(NULL, 0);
	scanf("%d", &n);
	for (int j = 0;j < 2;j++) for (int i = 0;i < n;i++)
	{
		scanf("%s", buf);
		root->upd(buf, 0, j, i+1);
	}
	root->solve();
	printf("%d\n", ans);
	for (int i = 0;i < n;i++)
		printf("%d %d\n", sol[i].first, sol[i].second);
	return 0;
}