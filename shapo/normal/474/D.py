import sys


MOD = 1_000_000_007

def main():
    iter_data = map(int, sys.stdin.read().split())
    t, k = next(iter_data), next(iter_data)
    all_tests = list(iter_data)
    max_n = max(all_tests)
    dp = [0] * (max_n + 1)
    dp[:k] = [1] * k
    for i in range(k, max_n + 1):
        dp[i] = (dp[i - 1] + dp[i - k]) % MOD
    p_sum = [0] * (max_n + 1)
    cur_val = 0
    for i in range(max_n + 1):
        p_sum[i] = cur_val = cur_val + dp[i]
    ans = [0] * t
    for t_id in range(t):
        a, b = all_tests[t_id * 2:t_id * 2 + 2]
        ans[t_id] = (p_sum[b] - p_sum[a - 1]) % MOD
    print(*ans, sep='\n')
        

if __name__ == '__main__':
    main()