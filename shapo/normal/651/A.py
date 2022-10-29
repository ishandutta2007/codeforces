if __name__ == '__main__':
    calc = [[0] * 201 for i in range(201)]
    
    for total in range(201):
        for a in range(total + 1):
            b = total - a
            
            variants = []
         
            # End game right now
            variants.append(0)
         
            # Charge first joystick: (a, b) -> (a + 1, b - 2)
            if b >= 2 and a > 0:
                variants.append(1 + calc[a + 1][b - 2])
         
            # Charge second joystick: (a, b) -> (a - 2, b + 1)
            if a >= 2 and b > 0:
                variants.append(1 + calc[a - 2][b + 1])
         
            calc[a][b] = max(variants)
    
    x, y = map(int, input().split())
    
    print(calc[x][y])