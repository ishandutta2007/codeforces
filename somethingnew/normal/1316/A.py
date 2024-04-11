for i in range(int(input())):
    n, m = map(int,input().split())
    mas = list(map(int,input().split()))
    print(min(m, sum(mas)))