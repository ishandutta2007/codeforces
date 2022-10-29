import collections
import itertools
import sys
import time


MOD = 998_244_353


def main():
    st = time.time()
    n, k = list(map(int, input().split()))
    all_input = sys.stdin.read().split()

    print('Read', time.time() - st, file=sys.stderr)

    rev = [1] * (n + 1)
    for i in range(2, n + 1):
        quot, rem = divmod(MOD, i)
        rev[i] = -quot * rev[rem] % MOD  # ignore global `% MOD`

    print('Rev', time.time() - st, file=sys.stderr)

    c_nk = [0] * (n + 1)
    c_nk[k] = val = 1
    for i, rev_val in zip(range(k + 1, n + 1), rev[1:]):
        c_nk[i] = val = val * i * rev_val % MOD

    print('Binom', time.time() - st, file=sys.stderr)

    events = collections.Counter(sorted(itertools.chain(
        (pos * 2 for pos in map(int, itertools.islice(all_input, None, None, 2))),
        (pos * 2 + 1 for pos in map(int, itertools.islice(all_input, 1, None, 2))),
    )))

    print('Sort', time.time() - st, file=sys.stderr)

    cnt = 0
    res = 0
    # Don't sort items of `collections.Counter`
    # We rely on fact that CPython implementaion of dict preserves input order
    # and hope that this holds for `collections.Counter`
    for typ, grp_cnt in events.items():
        if typ % 2 == 0:
            cnt, old_cnt = cnt + grp_cnt, cnt
            res += c_nk[cnt] - c_nk[old_cnt]
        else:
            cnt -= grp_cnt

    print('Calc', time.time() - st, file=sys.stderr)

    print(res % MOD)


if __name__ == '__main__':
    main()