a = sum(map(int, input().split()))
b = sum(map(int, input().split()))
c = int(input())
print("YES" if (a+4)//5+(b+9)//10<=c else "NO")