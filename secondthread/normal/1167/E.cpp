    #include <bits/stdc++.h>
     
    const int maxn=1000002;
     
    using namespace std;
    typedef pair<int, int> ii;
    typedef long long ll;
     
    int minHits[maxn];
    int main() {
    	ios_base::sync_with_stdio(false); cin.tie(NULL);
    	//brute force higher
    	//for every decrease a>b, need to erase either a or b
    	
    	//high value can only be x if highest decrease-To>=x 	<- precomp
    	//need to erase at least to min decreaseFrom					<- precomp
    	//need to erase to all decreaseTo with corresponding from
    	//greater than x																			<- sweep with set
    	for (int i=0; i<maxn; i++) minHits[i]=maxn;
    	
    	int n, maxVal; cin>>n>>maxVal;
    	vector<int> a;
    	for (int i=0; i<n; i++) {
    		int t; cin>>t;
    		a.push_back(t);
    	}
    	vector<ii> pairs;//value, index
    	for (int i=0; i<n; i++)
    		pairs.push_back({a[i], i});
    	sort(pairs.begin(), pairs.end());
    	set<int> seen;
    	ll ways=0;
    	int maxDecreaseTo=1;
    	int minDecreaseFrom=maxVal;
    	for (int i=n-1; i>=0; i--) {
    		seen.insert(a[i]);
    		if (seen.lower_bound(a[i])==seen.begin()) {
    			//no decreases
    			continue;
    		}
    		else {
    			minDecreaseFrom=min(minDecreaseFrom, a[i]);
    			maxDecreaseTo=max(maxDecreaseTo, *(--seen.lower_bound(a[i])));
    			minHits[a[i]]=min(minHits[a[i]], *seen.begin());
    		}
    	}
    	//cout<<"Min decrease from: "<<minDecreaseFrom<<" maxDecTo: "<<maxDecreaseTo<<endl;
    	for (int i=maxVal-1; i>=0; i--)
    		minHits[i]=min(minHits[i], minHits[i+1]);
    	
    	for (int upper=maxDecreaseTo; upper<=maxVal; upper++) {
    		int lower=minDecreaseFrom;
    		lower=min(lower, upper);
    		lower=min(lower, minHits[upper+1]);
    //		cout<<"upper: "<<upper<<" "<<lower<<endl;
    		ways+=(lower);
    	}
    	cout<<ways<<endl;
    	
    	return 0;
    }