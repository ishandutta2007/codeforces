#include <bits/stdc++.h>

const long long K = 1000000 + 7;
const long long inf = 10000000;
const long long up_bound = 1000000000000000;

std::vector<long long> primes;

long long a[K];
bool sieve[inf + 7];
long long mx[inf + 7];
long long cnt[inf + 7];

bool check(long long n)
{
    for(long long i = 0; i < primes.size(); i++)
    {
        long long pr = primes[i];
        long long curr_cnt = 0;
        
        while(pr <= n)
        {
            curr_cnt += n / pr;
            pr *= primes[i];
        }
        
        if(curr_cnt < cnt[i])
            return 0;
    }
    
    return 1;
}

int ind_of_prime[inf + 7];

int main()
{
   	std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    long long k;
    
    std::cin >> k;
    
    for(long long i = 0; i < k; i++)
    {
    	std::cin >> a[i];

    	cnt[a[i]]++;
    }

    //std::sort(a, a+k);
        
    for(long long i = 2; i <= inf; i++)
    {

        if(sieve[i])
            continue;
            
        primes.push_back(i);
        //cnt.push_back(0ll);

        mx[i] = i;

        ind_of_prime[i] = primes.size() - 1;
        
        for(long long j = 2*i; j <= inf; j += i)
        {
        	sieve[j] = true;
        	mx[j] = i;
        }
    }

    //std::cout << "ended\n";

    for(long long i = inf; i >= 2; i--)
    	cnt[i] += cnt[i+1];

    //std::cout << primes.size() << std::endl;
   
   	for(long long i = inf; i >= 2; i--)
   	{
   		if(mx[i] != i)
   			cnt[ mx[i] ] += cnt[i];
   		cnt[i / mx[i]] += cnt[i];
   	}

   	for(int i = 0; i < primes.size(); i++)
   	{
   		cnt[i] = cnt[primes[i]];
   		//std::cout << cnt[i] << " " << primes[i] << std::endl;
   	}
        
    long long l = 1, r = up_bound, mid;
    
    while(l != r)
    {
    	//std::cout << l << std::endl;

        mid = (l + r) >> 1ll;
        
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    
    std::cout << l << "\n";
    
    //std::cin.get();
    
    return 0;
}