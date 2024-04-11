#include<bits/stdc++.h>
#define intt long long
#define fr first
#define sc second
#define ii pair<intt,intt>
#define mk make_pair
#define pb push_back
using namespace std;
intt ans=0;
struct trie {
	trie* child[2];
	int mx=0;
	bool isLeaf;

	trie() {
		memset(child, 0, sizeof(child));
		isLeaf = 0;
	}

	void insertt(string& str,int now_i,int i) {
		if(i==42)
         return;
		else {
			int cur = str[i]-'0';
			if(child[cur] == 0 )
            {

				child[cur] = new trie();
				child[cur]->mx=now_i;
            }
			child[cur]->insertt(str,now_i,i+1);
		}
	}
	void chek(string& st1,int i,int nn)
	{

       if(i==42)
         return;
	    int nu=st1[i]-'0';
	    if(nu==0)
        {
            if(child[1]&&child[1]->mx>nn)
            {
                ans+=(1ll<<(41-i));
                child[1]->chek(st1,i+1,nn);
            }
            else if(child[0]&&child[0]->mx>nn)
            {

                child[0]->chek(st1,i+1,nn);
            }
        }
       else if(nu==1)
        {
            if(child[0]&&child[0]->mx>nn)
            {
                  ans+=(1ll<<(41-i));
                child[0]->chek(st1,i+1,nn);
            }
            else if(child[1]&&child[1]->mx>nn)
               child[1]->chek(st1,i+1,nn);
        }

	}


};
string f(intt num)
{
    string res;
    while(num!=0)
    {
        if(num%2==0)
            res+='0';
        else
            res+='1';
        num/=2;
    }
while(res.size()!=42)
 res+='0';
 reverse(res.begin(),res.end());
return res;
}

int main()
{
	trie root;
	int n;
	scanf("%d",&n);
string sss=f(0);
	root.insertt(sss,n,0);
	intt a[n];
	int i;
	for(i=0;i<n;i++)
        scanf("%I64d",&a[i]);
        intt x=0;
    for(i=n-1;i>=0;i--)
    {
         x^=a[i];
sss=f(x);
         root.insertt(sss,i,0);
    }
        intt res=0;
        x=0;
sss=f(x);
        root.chek(sss,0,-1);
        res=max(ans,res);
    for(i=0;i<n;i++)
    {
        x^=a[i];
        ans=0;
sss=f(x);
        root.chek(sss,0,i);
        res=max(res,ans);
    }
    printf("%I64d",res);




	return 0;
}