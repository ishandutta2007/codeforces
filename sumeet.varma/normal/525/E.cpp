#include <bits/stdc++.h>

#define sl ios::sync_with_stdio(0); cin.tie(0);
#define ll long long;

using namespace std;

    int bSFirst(vector<long long> a,long long key){
		int ret = -1;
		int s = 0, e = a.size();
		while(true){
			if(s==e) return ret;
			int mid = (s+e)/2;
			if(key==a[mid]) ret = mid;
			if(e-s==1) return ret;
			if(key<=a[mid])	e = mid;
			else s = mid+1;
		}
	}

	//Returns last occurrence of key when it is present else -1
	int bSLast(vector<long long> a,long long key){
		int start = 0,e = a.size();
		int ret = -1;
		while(true){
			if(start==e) return ret;
			int mid = (start+e)/2;
			if(key==a[mid]) ret = mid;
			if(e-start==1) return ret;
			if(key<a[mid])	e = mid;
			else start = mid+1;
		}
	}

	//Counts number of elements with a given value in a sorted array
	int bSCount(vector<long long> a,long long key){
		int startIndex = bSFirst(a,key);
		if(startIndex == -1)
			return 0;
		int endIndex = bSLast(a,key);
		return endIndex - startIndex + 1;
	}


int main(){ sl

    long long fact[19];
    int p3[19];
    fact[0] = p3[0] = 1;
    for(int i=1;i<=18;i++){
        fact[i] = i*fact[i-1];
        p3[i] = 3*p3[i-1];
    }

    int n,k;
    long long S;
    cin >> n >> k >> S;

    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];

    long long ans = 0;

    int left = n/2;
    int right = n - left;

    map<long long,long long> leftSums[k+1];
    map<long long,long long> rightSums[k+1];

    for(int i=1;i<p3[left];++i){

        bool posi = true;
        long long thisSum = 0;
        int num = i,c = 0, kC = 0;

        while(num != 0){
            int rem = num % 3;
            if(rem == 1)
                thisSum += a[c];
            else if(rem == 2){
                if(a[c] > 18){
                    posi = false;
                    break;
                }
                thisSum += fact[a[c]];
                kC++;
            }
            if(thisSum > S)
                break;
            c++;
            num /= 3;
        }

       if(posi && thisSum <= S && kC <= k){
            if(leftSums[kC].find(thisSum) == leftSums[kC].end())
                leftSums[kC].insert(make_pair(thisSum,1));
            else
                leftSums[kC][thisSum]++;
            if(thisSum == S)
                ans++;
       }

    }

     for(int i=1;i<p3[right];++i){

        bool posi = true;
        long long thisSum = 0;
        int num = i,c = left, kC = 0;

        while(num != 0){
            int rem = num % 3;
            if(rem == 1)
                thisSum += a[c];
            else if(rem == 2){
                if(a[c] > 18){
                    posi = false;
                    break;
                }
                thisSum += fact[a[c]];
                kC++;
            }
            if(thisSum > S)
                break;
            c++;
            num /= 3;
        }

        if(posi && thisSum <= S && kC <= k ){
            if(rightSums[kC].find(thisSum) == rightSums[kC].end())
                rightSums[kC].insert(make_pair(thisSum,1));
            else
                rightSums[kC][thisSum]++;
            if(thisSum == S)
                ans++;
        }
    }

    map<long long,long long>::iterator it;

    for(int i=0;i<=k;i++){
        for(it = leftSums[i].begin();it!=leftSums[i].end();++it){
            for(int b=0;b<=k-i;b++){
                if(rightSums[b].find(S - (it->first)) != rightSums[b].end())
                    ans += it->second * rightSums[b][S - (it->first)];
            }
        }
    }

    cout << ans;
    return 0;
}