import sys


def main():
    all_data = list(map(int, sys.stdin.read().split()))
    idx = 0
    t = all_data[idx]
    idx += 1
    for t_it in range(t):
        n, q = all_data[idx:idx+2]
        idx += 2
        a = [0] + all_data[idx:idx+n] + [0]
        idx += n
        all_ans = [0] * (q + 1)
        val = [0] * (n + 1)
        for i in range(n + 1):
            val[i] = max(a[i], a[i + 1])
        cur_ans = sum(val) - sum(a)
        all_ans[0] = cur_ans
        for q_it in range(1, q + 1):
            l, r = all_data[idx:idx+2]
            idx += 2
            if l != r:
                a[l], a[r] = a[r], a[l]
                for p in set((l - 1, l, r - 1, r)):
                    cur_ans -= val[p]
                    val[p] = max(a[p], a[p + 1])
                    cur_ans += val[p]
            all_ans[q_it] = cur_ans
        print(*all_ans, sep='\n')
        

if __name__ == '__main__':
    main()