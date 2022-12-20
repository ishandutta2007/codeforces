for _ in range(int(input())):
    n = int(input())
    arr = [int(x) for x in input().split()]
    arr.sort(reverse=True)
    score = 0
    for i, x in enumerate(arr):
        if (i + x) % 2 == 0:
            score += x if i%2 == 0 else -x
    if score == 0:
        print("Tie")
    elif score > 0:
        print("Alice")
    else:
        print("Bob")