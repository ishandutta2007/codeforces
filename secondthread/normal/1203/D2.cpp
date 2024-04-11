
#include <bits/stdc++.h>
using namespace std;

void println(vector<int> a) {
	for (int i:a) cout<<i<<" ";
	cout<<'\n';
}

bool isSubstr(string big, string sub) {
	int ind=0;
	for (char c:big)
		if (ind==sub.size()) return true;
		else if (sub[ind]==c) ind++;
	return ind==sub.size();
}

int brute(string big, string sub) {
	int n=big.size();
	int best=0;
	for (int i=0; i<n; i++)
		for (int j=i; j<n; j++) {
			string postRemove=big.substr(0, i).append(big.substr(j+1, n-(j+1)));
			if (isSubstr(postRemove, sub))
				best=max(best, j-i+1);
		}
	return best;
}

int solve(string big, string sub) {
	if (sub.size()==0) return big.size();
	int n=big.size();
	vector<int> forwardIndex(n), backwardsIndex(n);
	forwardIndex[0]=(big[0]==sub[0]?1:0);
	for (int i=1; i<n; i++) {
		if (forwardIndex[i-1]==sub.size()) forwardIndex[i]=sub.size();
		else if (big[i]==sub[forwardIndex[i-1]])
			forwardIndex[i]=forwardIndex[i-1]+1;
		else
			forwardIndex[i]=forwardIndex[i-1];
	}

	backwardsIndex[n-1]=(sub[sub.size()-1]==big[n-1]?sub.size()-2:sub.size()-1);
	for (int i=n-2; i>=0; i--) {
		if (backwardsIndex[i+1]==-1) backwardsIndex[i]=-1;
		else if (big[i]==sub[backwardsIndex[i+1]])
			backwardsIndex[i]=backwardsIndex[i+1]-1;
		else
			backwardsIndex[i]=backwardsIndex[i+1];
	}
	//println(forwardIndex);
	//println(backwardsIndex);
	vector<int> latest(n+1, 0);
	vector<int> earliest(n+1, 0);
	for (int i=0; i<n; i++)
		latest[backwardsIndex[i]+1]=i;
	for (int i=n-1; i>=0; i--)
		earliest[forwardIndex[i]]=i;

	int best=latest[0];//delete a prefix
	best=max(best, n-1-earliest[sub.size()]);//delete a suffix
	//cout<<"trimming ends: "<<best<<'\n';
	for (int i=0; i<n; i++) {
		//cout<<"\t"<<i<<" "<<latest[i]<<'\n';
		best=max(best, latest[forwardIndex[i]]-i-1);
	}
	return best;
}

mt19937 rng(5);
pair<string, string> genStrings() {
	int maxLen=10;
	int len1=rng()%maxLen+1;
	string a, b;
	for (int i=0; i<len1; i++)
		a.push_back('a'+(rng()%3));
	for (int i=0; i<len1; i++)
		if (rng()%2==0)
			b.push_back(a[i]);
	return {a, b};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string big, sub; cin>>big>>sub;
	int ans=solve(big, sub);
	cout<<ans<<'\n';
	for (int T=0; T<100; T++) {
		auto p=genStrings();
		int jury=brute(p.first, p.second);
		int myAns=solve(p.first, p.second);
		if (jury!=myAns) {
			cout<<"Broke!\n";
			cout<<p.first<<'\n'<<p.second<<'\n'<<"Answered: "<<myAns<<", expected: "
				<<jury<<'\n';
			break;
		}
	}
	return 0;
}