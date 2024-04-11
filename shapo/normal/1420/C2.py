import sys


def main():
    iter_data = map(int, sys.stdin.read().split())
    t = next(iter_data)
    for t_it in range(t):
        n, q = next(iter_data), next(iter_data)
        a = [0] + [next(iter_data) for _ in range(n)] + [0]
        all_ans = [0] * (q + 1)
        val = [0] * (n + 1)
        for i in range(n + 1):
            val[i] = max(a[i], a[i + 1])
        # Formula for array a
        # ans = max(a[0], a[1]) - a[0]
        #     + max(a[1], a[2]) - a[1]
        #       ...
        #     + max(a[n - 1], a[n]) - a[n - 1]
        cur_ans = sum(val) - sum(a)
        all_ans[0] = cur_ans
        for q_it in range(1, q + 1):
            l, r = next(iter_data), next(iter_data)
            if l != r:
                a[l], a[r] = a[r], a[l]
                cur_ans -= val[l - 1] + val[l] + val[r]
                val[l - 1] = max(a[l - 1], a[l])
                val[l] = max(a[l], a[l + 1])
                val[r] = max(a[r], a[r + 1])
                cur_ans += val[l - 1] + val[l] + val[r]
                if r - l > 1:
                    cur_ans -= val[r - 1]
                    val[r - 1] = max(a[r - 1], a[r])
                    cur_ans += val[r - 1]
            all_ans[q_it] = cur_ans
        print(*all_ans, sep='\n')
        

if __name__ == '__main__':
    main()