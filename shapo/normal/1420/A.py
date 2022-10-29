def case():
    n = int(input())
    a = list(map(int, input().split()))
    if all(a[i - 1] > a[i] for i in range(1, len(a))):
        print('NO')
    else:
        print('YES')
        

def main():
    t = int(input())
    for _ in range(t):
        case()
        

if __name__ == '__main__':
    main()