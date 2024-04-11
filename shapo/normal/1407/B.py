def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def run_test():
    n = int(input())
    a = list(map(int, input().split()))
    a = [(x, x) for x in a]
    res = []
    while a:
        next_gcd, next_val = max(a)
        a.remove((next_gcd, next_val))
        res.append(next_val)
        a = [(gcd(next_gcd, v), x) for v, x in a]
    print(*res)


def main():
    t = int(input())
    for _ in range(t):
        run_test()
        

if __name__ == '__main__':
    main()