#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MX 2005
#define ALL(v) (v).begin(),(v).end()

char s[MX], a[2][MX];
int ns, len[2];

bool match(int si,int k)
{
	if(si<0 || si>=ns || si+len[k]>ns) return false;
	for(int i=0;i<len[k];i++) if(s[si+i]!=a[k][i]) return false;
	return true;
}

class node
{
	public: 
		bool ends; 
		vector<node*> childPtr;
		vector<int> childId;
		node(){ ends=false; }
};

int ans = 0, pos;
node *root, *cur;
vector<node*>::iterator it1;
vector<int>::iterator it2;

void add(int i, int till)
{
	int k = s[i]-'a';
	it2 = lower_bound( ALL(cur->childId), k);
	it1 = cur->childPtr.begin() + ( it2 - cur->childId.begin() );
	
	if( it2 == cur->childId.end() || *it2 > k )
	{
		it2 = cur->childId.insert( it2, k );
		node *newBorn = new node();
		it1 = cur->childPtr.insert( it1, newBorn );
	}
	
	cur = *it1;

	if(i!=till) add(i+1,till);
	else{ if(!cur->ends) ans++; cur->ends=true; }
}

int main()
{
	scanf("%s %s %s",s,a[0],a[1]);
	ns = strlen(s);
	len[0] = strlen(a[0]);
	len[1] = strlen(a[1]);
	root = new node();
	for(int i=0;i<ns;i++) if(match(i,0))
	{
		cur = root;
		int last = i-1;
		for(int j=i+len[0]-1;j<ns;j++)
			if(j-len[1]+1>=i && match(j-len[1]+1,1))
				add(last+1,j), last = j;
	}

	printf("%d\n",ans);

	return 0;
}