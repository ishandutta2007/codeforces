def run_test():
    n = int(input())
    a = list(map(int, input().split()))
    n_0 = sum(1 for x in a if x == 0)
    res = []
    if n_0 < n // 2:  # remove '0's
        res = [x for x in a if x == 1]
        if len(res) % 2 == 1:  # we can remove at most one '1'
            res.pop()
    else:  # remove '1's
        res = [x for x in a if x == 0]
    print(len(res))
    print(' '.join(map(str, res)))
        

def main():
    t = int(input())
    for _ in range(t):
        run_test()


if __name__ == '__main__':
    main()