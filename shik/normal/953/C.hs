getInts = fmap (map read . words) getLine :: IO [Int]

conv ans cnt last [] = cnt:ans
conv ans cnt last (x:xs) =
    if last == x
       then conv ans (cnt + 1) last xs
       else conv (cnt:ans) 1 x xs

allTheSame xs = and $ map (== head xs) (tail xs)

solve (x:xs) =
    if allTheSame (conv [] 1 x xs)
       then "YES"
       else "NO"

main = do
    n <- getLine
    a <- getInts
    putStrLn $ solve a