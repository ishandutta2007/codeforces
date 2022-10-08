#include <bits/stdc++.h>

const int sent=-99999999;
using namespace std;

int goodFailFunction[51][26], badFailFunction[51][26];
int goodPrefixLen, badPrefixLen;
int dp[1001][51][51];
string text, good, bad;

int go(int textInd, int goodInd, int badInd) {
	//check memo
	if (goodInd==good.length())
		return 1+go(textInd, goodPrefixLen, badInd);
	if (badInd==bad.length())
		return -1+go(textInd, goodInd, badPrefixLen);
	if (textInd==text.length())
		return 0;
	if (dp[textInd][goodInd][badInd]!=sent)
		return dp[textInd][goodInd][badInd];
	int best=sent+1;
	for (int toPlace=0; toPlace<26; toPlace++) {
		if (text[textInd]!='*'&&text[textInd]!='a'+toPlace) continue;
		int newGood=goodFailFunction[goodInd][toPlace];
		int newBad=badFailFunction[badInd][toPlace];
		//cout<<"\tIf placing "<<toPlace<<" newGood: "<<newGood<<" new bad: "<<newBad<<endl;
		best=max(best, go(textInd+1, newGood, newBad));
	}

	return dp[textInd][goodInd][badInd]=best;
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>text>>good>>bad;

	int n=text.length();
	//build the failure functions
	for (int nMatched=0; nMatched<good.length(); nMatched++) {
		for (char nextPlaced='a'; nextPlaced<='z'; nextPlaced++) {
			string word=good.substr(0, nMatched);
			word.push_back(nextPlaced);
			goodFailFunction[nMatched][nextPlaced-'a']=0;
			for (int cand=1; cand<=nMatched+1; cand++) {
				bool works=true;
				for (int i=0; i<cand; i++)
					if (i>=good.length()||word[word.length()-cand+i]!=good[i])
						works=false;
				if (works)
					goodFailFunction[nMatched][nextPlaced-'a']=cand;
			}
		}
	}
	for (int nMatched=0; nMatched<bad.length(); nMatched++) {
		for (char nextPlaced='a'; nextPlaced<='z'; nextPlaced++) {
			string word=bad.substr(0, nMatched);
			word.push_back(nextPlaced);
			badFailFunction[nMatched][nextPlaced-'a']=0;
			for (int cand=1; cand<=nMatched+1; cand++) {
				bool works=true;
				for (int i=0; i<cand; i++)
					if (i>=bad.length()||word[word.length()-cand+i]!=bad[i])
						works=false;
				if (works)
					badFailFunction[nMatched][nextPlaced-'a']=cand;
			}
		}
	}
	
	//calculate good and bad prefix lengths
	for (int cand=0; cand<good.length(); cand++) {
		bool works=true;
		for (int i=0; i<cand; i++)
			if (good[i]!=good[good.length()-cand+i])
				works=false;
		if (works)
			goodPrefixLen=cand;
	}
	for (int cand=0; cand<bad.length(); cand++) {
		bool works=true;
		for (int i=0; i<cand; i++)
			if (bad[i]!=bad[bad.length()-cand+i])
				works=false;
		if (works)
			badPrefixLen=cand;
	}

	for (int i=0; i<text.length(); i++)
		for (int j=0; j<good.length(); j++)
			for (int k=0; k<bad.length(); k++)
				dp[i][j][k]=sent;
	int ans=go(0, 0, 0);
	cout<<ans<<endl;

	return 0;
}