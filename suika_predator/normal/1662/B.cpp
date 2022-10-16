#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> solve(auto ABC,auto AB,auto AC,auto BC,auto A,auto B,auto C)
{
	vector<pair<int,int>> ret;
	for(auto ch:ABC)ret.push_back({ch,ch});
	while(not BC.empty() and not A.empty())
	{
		ret.push_back({BC.back(),A.back()});
		BC.pop_back();
		A.pop_back();
	}
	for(auto ch:BC)
	{
		B.push_back(ch);
		C.push_back(ch);
	}
	while(not AC.empty() and not B.empty())
	{
		ret.push_back({AC.back(),B.back()});
		AC.pop_back();
		B.pop_back();
	}
	for(auto ch:AC)
	{
		A.push_back(ch);
		C.push_back(ch);
	}
	while(not AB.empty() and not C.empty())
	{
		ret.push_back({AB.back(),C.back()});
		AB.pop_back();
		C.pop_back();
	}
	for(auto ch:AB)
	{
		A.push_back(ch);
		B.push_back(ch);
	}
	while(A.empty()+B.empty()+C.empty()<2)
	{
		if(C.size()==min({A.size(),B.size(),C.size()}))
		{
			ret.push_back({A.back(),B.back()});
			A.pop_back();
			B.pop_back();
		}
		else if(B.size()==min({A.size(),B.size(),C.size()}))
		{
			ret.push_back({A.back(),C.back()});
			A.pop_back();
			C.pop_back();
		}
		else
		{
			ret.push_back({B.back(),C.back()});
			B.pop_back();
			C.pop_back();
		}
	}
	for(auto ch:A)ret.push_back({ch,ch});
	for(auto ch:B)ret.push_back({ch,ch});
	for(auto ch:C)ret.push_back({ch,ch});
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	string a,b,c;
	cin>>a>>b>>c;
	vector<int> cnta(26),cntb(26),cntc(26);
	for(auto ch:a)
	{
		cnta[ch-'A']++;
	}
	for(auto ch:b)
	{
		cntb[ch-'A']++;
	}
	for(auto ch:c)
	{
		cntc[ch-'A']++;
	}
	vector<int> ABC,AB,AC,BC,A,B,C;
	for(int i=0;i<26;i++)
	{
		auto ins=[&](vector<int> &vec,int x)
		{
			for(int j=1;j<=x;j++)vec.push_back(i);
		};
		auto fuck=[&](vector<int> &ABC,vector<int> &AB,vector<int> &A,vector<int> &AC,vector<int> &BC,int cnta,int cntb,int cntc)
		{
			int mn=min(cntc,cnta-cntb);
			ins(ABC,(cntc-mn)%2);
			ins(AB,cntb-cntc+mn+(cntc-mn)/2);
			ins(A,cnta-cntb-mn);
			ins(AC,mn+(cntc-mn)/2);
			ins(BC,(cntc-mn)/2);
		};
		if(cnta[i]==max({cnta[i],cntb[i],cntc[i]}))
		{
			if(cntb[i]>cntc[i])//A>B>C
			{
				fuck(ABC,AB,A,AC,BC,cnta[i],cntb[i],cntc[i]);
			}
			else//A>C>B
			{
				fuck(ABC,AC,A,AB,BC,cnta[i],cntc[i],cntb[i]);
			}
		}
		else if(cntb[i]==max({cnta[i],cntb[i],cntc[i]}))
		{
			if(cnta[i]>cntc[i])//B>A>C
			{
				fuck(ABC,AB,B,BC,AC,cntb[i],cnta[i],cntc[i]);
			}
			else//B>C>A
			{
				fuck(ABC,BC,B,AB,AC,cntb[i],cntc[i],cnta[i]);
			}
		}
		else
		{
			if(cnta[i]>cntb[i])//C>A>B
			{
				fuck(ABC,AC,C,BC,AB,cntc[i],cnta[i],cntb[i]);
			}
			else//C>B>A
			{
				fuck(ABC,BC,C,AC,AB,cntc[i],cntb[i],cnta[i]);
			}
		}
	}
//	cerr<<"ABC ";for(auto z:ABC)cerr<<(char)(z+'A');cerr<<endl;
//	cerr<<"AB ";for(auto z:AB)cerr<<(char)(z+'A');cerr<<endl;
//	cerr<<"AC ";for(auto z:AC)cerr<<(char)(z+'A');cerr<<endl;
//	cerr<<"BC ";for(auto z:BC)cerr<<(char)(z+'A');cerr<<endl;
//	cerr<<"A ";for(auto z:A)cerr<<(char)(z+'A');cerr<<endl;
//	cerr<<"B ";for(auto z:B)cerr<<(char)(z+'A');cerr<<endl;
//	cerr<<"C ";for(auto z:C)cerr<<(char)(z+'A');cerr<<endl;
	auto vec=solve(ABC,AB,AC,BC,A,B,C);
	cout<<vec.size()<<endl;
	for(auto [u,v]:vec)
	{
		cout<<(char)(u+'A')<<(char)(v+'A')<<'\n';
	}
	return 0;
}